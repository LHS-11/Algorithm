#include<bits/stdc++.h>
using namespace std;
int n, m; // 세로, 가로
int a, b, c, d; // x 는 세로, y는 가로
string s[301];
int vis[301][301];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> a >> b >> c >> d;

	for (int i = 0; i < n; i++) cin >> s[i];

	int cnt = 0;
	int flag = 0;
	while (1) {
		queue<pair<int, int>> q;
		queue<pair<int, int>> q1;
		fill(&vis[0][0], &vis[0][0] + 301 * 301, 0);

		q.push({ a-1,b-1 });
		vis[a-1][b-1] = 1;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			if (cur.first == c-1 && cur.second == d-1) {
				flag = 1;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (!vis[nx][ny]) {
					if (s[nx][ny] == '0' || s[nx][ny] == '#') {
						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
					else if (s[nx][ny] == '1') {
						q1.push({ nx,ny });
					}
				}
			}
		}
		cnt++;
		if (flag) break;
		while (!q1.empty()) {
			auto cur = q1.front();
			q1.pop();
			s[cur.first][cur.second] = '0';
		}
		
	}
	cout << cnt;
}