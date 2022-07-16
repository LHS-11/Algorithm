#include<bits/stdc++.h>
using namespace std;
int n;
int a[201][201];
int vis[201][201];
int vis1[201][201];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
vector<pair<int, int>>v;
int ans = 987654321;
bool check(int a, int b) { // 무작위로 3개를 뽑아서 체크 함수를 통해서 겹치지 않는지 확인 , 애초에 3개를 뽑을 때 체킹을 하면 시간을 훨씬 줄일 수 있음
	vis1[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = a + dy[i];
		int nx = b + dx[i];
		if (vis1[ny][nx]) {
			return false;
		}
		else {
			vis1[ny][nx] = 1;
		}
	}
	return true;
}
void go(int idx, int k) {

	if (k == 3) {
		memset(vis1, 0, sizeof(vis));
		int flag = 0;
		for (auto c : v) {
			if (!check(c.first, c.second)) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			int sum = 0;
			for (auto c : v) {
				sum += a[c.first][c.second];
				for (int i = 0; i < 4; i++) {
					sum += a[c.first + dy[i]][c.second + dx[i]];
				}
			}
			ans = min(ans, sum);
		}
		return;
	}

	for (int i = idx; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (vis[i][j]) continue;
			vis[i][j] = 1;
			v.push_back({ i,j });
			go(i, k + 1);
			vis[i][j] = 0;
			v.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	go(1, 0);
	cout << ans;

}