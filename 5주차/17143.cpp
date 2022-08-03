#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0,0,1,-1 };
int dy[4] = {-1,1,0,0 };
int r, c, m; // 가로,세로 , 상어의 수
int board[104][104];
int vis[104][104];
vector<tuple<int, int, int, int, int>>shark;
vector <tuple<int, int, int, int, int>>shk;
void go() {
	for (int i = 0; i < shark.size(); i++) {
		int r, c, s, d, z;
		tie(r, c, s, d, z) = shark[i];

		int nx, ny;
		if (board[r][c] == -1) continue;
		for (int i = 0; i < s; i++) {
			nx = c + dx[d];
			ny = r + dy[d];
			if (nx == 1 || nx == c || ny==1 || ny==r) d += 1;
			if (d == 4) d = 2;
		}
		shk.push_back({ nx,ny,s,d,z });
	}
	sort(shk.begin(), shk.end());
	shark.clear();
	memset(board, 0, sizeof(board));
	for (int i = 0; i < shk.size(); i++) {
		int r, c, s, d, z;
		tie(r, c, s, d, z) = shk[i];
		if (board[r][c] && board[r][c] < z) {
			shark.pop_back();
			board[r][c] = z;
		}
		else if(!board[r][c]){
			board[r][c] = z;
		}
		shark.push_back({ r,c,s,d,z });
	}
	shk.clear();
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e; // 속력, 이동방향, 크기
		shark.push_back({ a,b,c,d-1,e });
		board[a][b] = e;
	}
	
	int sum = 0;
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) {
			if (board[j][i]) {
				sum += board[j][i];
				board[j][i] = -1;
				break;
			}
		}
		go();
	}
	cout << sum;
}
