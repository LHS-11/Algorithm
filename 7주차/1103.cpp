#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
string a[54];
int vis[54][54];
int dp[54][54];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dfs(int x, int y) {

	if (vis[y][x]) { 
		cout << -1;
		exit(0);
	} 
	int& ans = dp[y][x];
	if (ans) return ans;
	vis[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + (a[y][x]-'0') * dx[i];
		int ny = y + (a[y][x]-'0') *dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (a[ny][nx] != 'H') {
			ans = max(ans, dfs(nx, ny)+1);
		}
	}
	vis[y][x] = 0;
	return ans;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];
	cout << dfs(0,0)+1;
}