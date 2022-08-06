#include<bits/stdc++.h>
using namespace std;
int n, m;
int ans = 100;
int a[9][9];
int board[9][9];
int dx[4] = { -1,0,1,0 }; // 서북동남
int dy[4] = { 0,-1,0,1 };
int vis[8];
vector<pair<int, int>> v;
void go(int x,int y,int k) {
	
	int nx = x + dx[k];
	int ny = y + dy[k];
	if (nx < 0 || nx >= m || ny < 0 || ny >= n) return;
	if (a[ny][nx] == 6) return;
	board[ny][nx] = -1;
	go(nx, ny, k);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] >= 1 && a[i][j] <= 5) v.push_back({ i,j });
		}
	}

	for (int i = 0; i < (1 <<(2 * v.size())); i++) { // 00,01,10,11 -> 총 4가지 방향을 바꾸는 경우의 수가 있기 때문에 하나의 cctv당 두개의 비트가 필요
		
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				board[j][k] = a[j][k];
			}
		}
		int tmp = i;

		for (int j = 0; j < v.size(); j++) {
			int dir = tmp % 4;
			tmp /= 4;

			int x = v[j].second;
			int y = v[j].first;

			if (a[y][x] == 1) {
				go(x, y, dir);
			}
			else if (a[y][x] == 2) {
				go(x, y, dir);
				go(x, y, (dir+2)%4);
			}
			else if (a[y][x] == 3) {
				go(x, y, dir);
				go(x, y, (dir+1)%4);
			}
			else if (a[y][x] == 4) {
				go(x, y, dir);
				go(x, y, (dir+1)%4);
				go(x, y, (dir+2)%4);
			}
			else {
				go(x, y, dir);
				go(x, y, (dir + 1)%4);
				go(x, y, (dir + 2)%4);
				go(x, y, (dir+3)%4);
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) sum++;
			}
		}
		ans = min(ans, sum);
	}
	cout << ans;
}
