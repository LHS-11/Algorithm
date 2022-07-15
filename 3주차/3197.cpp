#include<bits/stdc++.h>
using namespace std;
int r, c; // r 세로, c 가로
int vis[1501][1501];
string s[1501];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<pair<int, int>> v;
queue<pair<int, int>> q1; // 매일 얼음이 녹아서 물이 되는 곳 갱신
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s[i];
		for (int j = 0; j < c; j++) {
			if (s[i][j] == 'L') {
				v.push_back({ i,j }); // 백조의 좌표
			}
			if (s[i][j] != 'X') q1.push({ i,j });
		}
	}
	queue<pair<int, int>> q;
	q.push(v[0]);
	vis[v[0].first][v[0].second] = 1;
	
	int cnt = 0;
	while (1) {
		queue<pair<int, int>> qq; // 시간을 줄이기 위해 백조의 위치를 계속 움직여서 갱신
		int flag = 0;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			if (cur.first == v[1].first && cur.second == v[1].second) {
				flag = 1;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cur.second + dx[i];
				int ny = cur.first + dy[i];
				if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
				if (!vis[ny][nx]) {
					if (s[ny][nx] == 'X') qq.push({ ny,nx });
					else {
						q.push({ ny,nx });
					}
					vis[ny][nx] = 1; // 메모리 초과를 막기 위해서 방문한 곳 최대한 줄여줌
				}
			}
		}
		q = qq;
		if (flag) break;
		cnt++;
		int sz = q1.size();
		while (sz--) {
			auto cur = q1.front();
			q1.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.second + dx[i];
				int ny = cur.first + dy[i];
				if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
				if (s[ny][nx] == 'X') {
					s[ny][nx] = '.';
					q1.push({ ny,nx });
				}
			}
		}
		
	}
	cout << cnt;
}
