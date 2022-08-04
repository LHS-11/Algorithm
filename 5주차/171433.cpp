#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0,0,1,-1 };
int dy[4] = {-1,1,0,0 };
int r, c, m; // 세로,가로 , 상어의 수
int board[104][104];
int vis[104][104];
vector<tuple<int, int, int, int, int>>shark;
vector <tuple<int, int, int, int, int>>shk;
void go() {
	for (int i = 0; i < shark.size(); i++) {
		int r1, c1, s, d, z; // 세로, 가로
		tie(r1, c1, s, d, z) = shark[i];

		int nx=c1, ny=r1;
		if (board[r1][c1] == -1) continue;
		for (int i = 0; i < s; i++) {
			nx = nx + dx[d];
			ny = ny + dy[d];
			if (nx == 0 || nx == c+1 || ny == 0 || ny == r+1) { //테두리만 처리하면 되는데 
				d++;
				if (d == 4) d = 2;
				else if (d == 2) d = 0;
				nx = nx + dx[d];
				nx = nx + dx[d];
				ny = ny + dy[d];
				ny = ny + dy[d];
			}
		}
		shk.push_back({ ny,nx,s,d,z });
	}
	sort(shk.begin(), shk.end());
	shark.clear();
	memset(board, 0, sizeof(board));
	for (int i = 0; i < shk.size(); i++) {
		int r2, c2, s, d, z;
		tie(r2, c2, s, d, z) = shk[i];
		if (board[r2][c2] && board[r2][c2] < z) {
			shark.pop_back();
			board[r2][c2] = z;
		}
		else if(!board[r2][c2]){
			board[r2][c2] = z;
		}
		shark.push_back({ r2,c2,s,d,z });
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
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
		cout << i <<' '<<sum << endl;
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
