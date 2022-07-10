#include<bits/stdc++.h>
using namespace std;
int r, c;
int vis[1001][1001];
int vis1[1001][1001];
string s[1001];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c;

	queue<pair<int, int>> q;
	queue<pair<int, int>> fire;

	for (int i = 0; i < r; i++) {
		cin >> s[i];
		for (int j = 0; j < c; j++) {
			if (s[i][j] == 'J') {
				q.push({ i,j });
				vis[i][j] = 1;
			}
			if (s[i][j] == 'F') {
				fire.push({ i,j });
				vis1[i][j] = 1;
			}
		}
	}

	while (1) {
		queue < pair<int, int>>q1;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			if (vis1[cur.first][cur.second]) continue;
			for (int i = 0; i < 4; i++) {
				int nx = cur.second + dx[i];
				int ny = cur.first + dy[i];

				if (nx < 0 || nx >= c || ny < 0 || ny >= r) {
					cout << vis[cur.first][cur.second];
					return 0;
				}
				if (!vis[ny][nx] && s[ny][nx] == '.' && !vis1[ny][nx]) {
					q1.push({ ny,nx });
					vis[ny][nx] = vis[cur.first][cur.second] + 1;
				}
			}
		}
		queue<pair<int, int>>fire1;
		while (!fire.empty()) {
			auto curFire = fire.front();
			fire.pop();
			for (int i = 0; i < 4; i++) {
				int nx = curFire.second + dx[i];
				int ny = curFire.first + dy[i];
				if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
				if (!vis1[ny][nx] && s[ny][nx] != '#') {
					fire1.push({ ny,nx });
					vis1[ny][nx] = 1;
				}
			}
		}
		fire = fire1;
		q = q1;
		if (q.empty()) break;
	}
	cout << "IMPOSSIBLE";
}
