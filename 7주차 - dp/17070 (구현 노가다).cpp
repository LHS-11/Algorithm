#include<bits/stdc++.h>
using namespace std;
int n,  a[17][17], cnt;
int dx[3] = { 1,0,1 }; // 가로, 세로, 대각선
int dy[3] = { 0,1,1 };
int vis[17][17];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}

	a[0][0] = 1;
	a[0][1] = 1;

	queue<tuple<int, int, int>>q;
	q.push({ 1,0,0 }); // 0 :가로 , 2 : 대각선 , 1 : 세로
	while (!q.empty()) {
		int x, y, k;
		tie(x, y, k) = q.front();
		q.pop();

		if (x == n - 1 && y == n - 1) {
			cnt++;
		}
		if (x < 0 || y < 0 || x >= n || y >= n) continue;
		if (k == 0) { // 가로 방향일 때
			for (int i : {0, 2}) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (i==0 &&a[ny][nx] != 1) {
					q.push({ nx,ny,0 });
				}
				else if (i == 2 && a[y + 1][x] != 1 && a[y][x + 1] != 1 && a[y + 1][x + 1]!= 1) {
					q.push({ nx,ny,2 });
				}
			}
		}
		else if (k == 1) { // 세로 방향일 때
			for (int i : {1, 2}) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (i == 1 && a[ny][nx] != 1) q.push({ nx,ny,1 });
				else if (i == 2 && a[y + 1][x] != 1 && a[y][x + 1] != 1 && a[y + 1][x + 1] != 1) q.push({ nx,ny,2 });
			}
		}
		else { // 대각선일 때
			for (int i : {0, 1, 2}) { 
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (i == 0 && a[ny][nx] != 1) q.push({ nx,ny,0 });
				else if (i == 1 && a[ny][nx] != 1) q.push({ nx,ny,1 });
				else if (i == 2 && a[y + 1][x] != 1 && a[y][x + 1] != 1 && a[y + 1][x + 1] != 1) q.push({ nx,ny,2 });
			}
		}
	}
	cout << cnt;
}