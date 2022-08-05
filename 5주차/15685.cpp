#include<bits/stdc++.h>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int n;
int board[104][104];
vector<pair<int, int>> v1;
pair<int, int> rotate(int startX, int startY, int baseX, int baseY, vector<pair<int, int>> v) {
	int sz = 0;
	int x1, y1;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		int nx = (baseY - y) + baseX;
		int ny = -(baseX - x) + baseY;
		if (nx < 0 || ny < 0 || nx>100 || ny>100) continue;
		board[ny][nx] = 1;
		v1.push_back({ nx,ny });

		if (x == startX && y == startY) { // 처음 시작점을 회전 시킬때마다 끝점이 된다.
			x1 = nx;
			y1 = ny;
		}
	}
	pair<int, int> p = { x1,y1 };
	return p;
}
void go(int x, int y, int dir, int sz) { // 회전변환 시계 방향으로 90도 = 반시계 방향으로 270도

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	v1.push_back({ x,y }); // v1 배열에 현재 좌표 다 담기
	v1.push_back({ nx,ny });

	board[y][x] = 1;
	board[ny][nx] = 1;

	for (int i = 1; i <= sz; i++) {
		auto cur = rotate(x, y, nx, ny, v1); // 90도 시계방향으로 회전, 끝점 잡기 cur로 계속 업데이트
		nx = cur.first;
		ny = cur.second;
	}
	v1.clear();
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		go(x, y, d, g);
	}
	int ans = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) {
				ans++;
			}
		}
	}
	cout << ans;
}
