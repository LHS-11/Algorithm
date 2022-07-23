#include<bits/stdc++.h>
using namespace std;
int n, m;
int vis[51][51];
int vis1[51][51][2];
int a[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ans1, ans2, ans3;
int sz[2501];
int dfs(int x,int y,int cnt) {
	
	vis[y][x] = cnt;
	int rst = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!(a[y][x] & (1 << i))) {
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (!vis[ny][nx]) {
				rst += dfs(nx, ny,cnt);
			}
		}
	}
	return rst;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				ans1++;
				sz[ans1] = dfs(j, i, ans1); // 각 구역마다 번호를 지정
				ans2 = max(ans2, sz[ans1]); // 각 구역의 넓이의 최댓값 갱신
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i+1<m && vis[i][j]!=vis[i+1][j]) { // 구역의 경계를 확인
				ans3 = max(ans3, sz[vis[i][j]] + sz[vis[i + 1][j]]);
			}
			if (j + 1 < n && vis[i][j] != vis[i][j + 1]) {
				ans3 = max(ans3, sz[vis[i][j]] + sz[vis[i][j + 1]]);
			}
		}
	}

	cout << ans1 << '\n' << ans2 << '\n' << ans3;
}