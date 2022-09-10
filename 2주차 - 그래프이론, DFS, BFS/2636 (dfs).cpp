#include<bits/stdc++.h>
using namespace std;
int n, m; // 세로 , 가로
int board[101][101];
int vis[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<pair<int, int>> v;
void dfs(int y, int x) {

	if (board[y][x] == 1) {
		v.push_back({ y,x });
		return;
	}

	vis[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		
		if (!vis[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int time = 0;
	int area;
	while (1) {
		area = 0;
		fill(&vis[0][0], &vis[0][0] + 100 * 100, 0);
		v.clear();
		dfs(0, 0);
		
		for (auto c : v) {
			if (board[c.first][c.second] == 1) area++;
			board[c.first][c.second] = 0;
		}
		time++;
		int flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j]) flag = 1;
			}
		}
		if (!flag) break;
	}
	cout << time << '\n' << area;
}
