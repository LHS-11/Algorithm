#include<bits/stdc++.h>
using namespace std;
int r, c, t,tmp,tmp1; // r: 행 (세로) , c: 열 (가로)
int a[54][54], board[54][54];
vector<int> v;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
queue<pair<int, int>> q;
queue<pair<int, int>> q1; // 다음번에 풀때는 그냥 범위를 1~r , 1~c로 둬서 풀자!.. 헷갈리는 경우가 많다
void go(int y) { // 바람 위쪽 시계 반대 방향 이동 
	for (int i = y-1; i >=1; i--) {
		a[i][0] = a[i - 1][0];
	}
	for (int i = 0; i < c-1; i++) {
		a[0][i] = a[0][i + 1];
	}
	for (int i = 0; i < y; i++) {
		a[i][c - 1] = a[i + 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		a[y][i] = a[y][i - 1];
	}
	a[y][1] = 0;
}
void go1(int y) { // 바람 아래쪽 시계 방향 이동
	for (int i = y + 1; i <r-1; i++) {
		a[i][0] = a[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		a[r-1][i] = a[r-1][i + 1];
	}
	for (int i = r-1; i >=y; i--) { // r-1 : 6 , y= 4
		a[i][c - 1] = a[i - 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		a[y][i] = a[y][i - 1];
	}
	a[y][1] = 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) v.push_back(i);
			else if (a[i][j]>0) q.push({ i,j });
		}
	}
	int sum = 0;
	while (t--) {
		memset(board, 0, sizeof(board));
		sum = 0;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int nx = cur.second + dx[i];
				int ny = cur.first + dy[i];
				if (nx<0 || ny<0 || nx>=c || ny>=r) continue;
				if (a[ny][nx] != -1) {
					board[ny][nx] += a[cur.first][cur.second] / 5;
					cnt++;
				}
			}
			board[cur.first][cur.second] += a[cur.first][cur.second]-(a[cur.first][cur.second] / 5) * cnt;
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] != -1) a[i][j] = board[i][j];
			}
		}
		go(v[0]);
		go1(v[1]);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] > 0) {
					sum += a[i][j];
					q.push({ i,j });
				}
			}
		}
	}
	cout << sum;

}