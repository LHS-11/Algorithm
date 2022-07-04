#include<bits/stdc++.h>
using namespace std;
int n, m; // 세로, 가로
int a[9][9];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int chk[9][9];
int vis[9][9];
int ans = 0;
void combi(int x, int y, int k) {
	if (k == 3) { // 기저 조건 벽이 3 개 일때 
		aaa++;
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 2) {
					q.push({ i,j });
					vis[i][j] = 1;
				}
			}
		}

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.second + dx[i];
				int ny = cur.first + dy[i];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
				if (!vis[ny][nx] && a[ny][nx] == 0) {
					q.push({ ny,nx });
					vis[ny][nx] = 1;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis[i][j] && a[i][j] == 0) cnt++;
			}
		}
		ans = max(ans, cnt);

		memset(vis, 0, sizeof(vis));
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j]) continue;
			chk[i][j] = 1;
			a[i][j] = 1;
			combi(i, j, k + 1);
			a[i][j] = 0;
			chk[i][j] = 0;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) chk[i][j] = 1;
		}
	}

	combi(0, 0, 0);
	cout << ans;
}
