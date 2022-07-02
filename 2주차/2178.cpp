#include<bits/stdc++.h>
using namespace std;
string s[101];
int n, m;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int vis[101][101];
queue<pair<int, int>>q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> s[i];

	vis[0][0] = 1;
	q.push({ 0,0 });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.first == m - 1 && cur.second == n - 1) { // n : 4, m : 6
			cout << vis[n-1][m-1];
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= m  || ny < 0 || ny >= n) continue;

			if (!vis[ny][nx] && s[ny][nx] == '1') {
				vis[ny][nx] = vis[cur.second][cur.first] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
