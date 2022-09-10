#include<bits/stdc++.h>
using namespace std;
int n, m; // 세로, 가로 길이 
int a[101][101];
int vis[101][101];
int chk[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int> ans;
int cnt = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j]) cnt++;
		}
	}
	ans.push_back(cnt);
	int time = 0;
	while (1) {


		cnt = 0;
		memset(chk, 0, sizeof(chk));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) {
					queue<pair<int, int>> q;
					memset(vis, 0, sizeof(vis));
					int flag = 0;
					q.push({ i,j });
					while (!q.empty()) {
						auto cur = q.front();
						q.pop();
						for (int k = 0; k < 4; k++) {
							int nx = cur.second + dx[k];
							int ny = cur.first + dy[k];
							if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
								chk[i][j] = 1;
								flag = 1;
								break;
							}
							if (!vis[ny][nx] && a[ny][nx] == 0) {
								vis[ny][nx] = 1;
								q.push({ ny,nx });
							}
						}
						if (flag) break;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (chk[i][j]) a[i][j] = 0;
				else if (!chk[i][j] && a[i][j]) cnt++;
			}
		}
		time++;
		cout << time << ' ' << cnt << endl;
		if (cnt == 0) {
			break;
		}
		ans.push_back(cnt);
	}
	cout << time << '\n' << ans[ans.size() - 1];

}
