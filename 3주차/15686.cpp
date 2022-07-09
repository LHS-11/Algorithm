#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[51][51];
vector<pair<int, int>> chk;
vector<pair<int, int>> choice;
const int INF=987654321;
int vis[51][51];
int vis1[14];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int mn;
int ans=INF;
void go(int idx, int k) {

	if (k == m) {
		mn = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) {
					int dis = INF;
					for (int t = 0; t < choice.size(); t++) {
						int distance = abs(i - choice[t].first) + abs(j - choice[t].second);
						dis = min(dis, distance);
					}
					mn += dis;
				}
			}
		}
		ans = min(ans, mn);
	}

	for (int i = idx; i < chk.size(); i++) {
		int y = chk[i].first; int x = chk[i].second;
		if (vis1[i]) continue;
		vis1[i] = 1;
		choice.push_back({ y,x });
		go(i + 1, k + 1);
		choice.pop_back();
		vis1[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) chk.push_back({ i,j });
		}
	}
	go(0, 0);
	cout << ans;

}
