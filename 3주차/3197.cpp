#include<bits/stdc++.h>
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int vis[21][21];
int r, c; // r은 세로, c는 가로
string s[21];
int chk[27];
int mx, cnt = 1;
void dfs(int x, int y) {
	mx = max(cnt, mx);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
		if (!vis[ny][nx] && !chk[s[ny][nx] - 'A']) {
			vis[ny][nx] = 1;
			chk[s[ny][nx] - 'A']++;
			cnt++;
			dfs(nx, ny);
			cnt--;
			vis[ny][nx] = 0;
			chk[s[ny][nx] - 'A']--;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> s[i];

	vis[0][0] = 1;
	chk[s[0][0] - 'A']++;
	dfs(0, 0);
	cout << mx;
}