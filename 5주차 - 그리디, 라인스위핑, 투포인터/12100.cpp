#include<bits/stdc++.h>
using namespace std;
int n;
int a[24][24];
int board[24][24];
void rotate(int board[24][24]) {
	int temp[24][24];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = board[n - j - 1][i]; // 오른쪽으로 회전
		}
	}
	memcpy(board, temp, sizeof(temp)); // 복사 memcpy(복사해서 넣으려는 배열, 복사하려는 배열, sizeof(복사하려는배열))
}
void go(int board[24][24]) { // 왼쪽으로 합치기 
	int temp[24][24];
	for (int i = 0; i < n; i++) {
		int idx = -1, chk = 0;
		for (int j = 0; j < n; j++) {
			if (board[i][j]==0) continue;
			if (chk && board[i][j] == temp[i][idx]) temp[i][idx] *= 2, chk = 0; // 같은 수가 있을때 합치기
			else temp[i][++idx] = board[i][j], chk = 1; // 숫자가 있다면 idx 하나 더하고, 체킹
		}
		for (idx++; idx < n; idx++) temp[i][idx] = 0; // 나머지 인덱스 0으로 채우기
	}
	memcpy(board, temp, sizeof(temp));
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << 10); i++) { // (00,01,10,11) => 4방향 (2) * 5 = 10
		int tmp = i;
		memcpy(board, a, sizeof(a));
		for(int k=0;k<5;k++) { // 5번 이동 가능
			int t = tmp % 4;
			tmp /= 4;
			if (t == 0) { // 왼쪽으로 이동
				go(board);
			}
			else if (t == 1) { // 아래로 이동
				rotate(board);
				go(board);
			}
			else if (t == 2) { // 오른쪽으로 이동
				rotate(board);
				rotate(board);
				go(board);
			}
			else if(t==3){ // 위로 이동
				rotate(board);
				rotate(board);
				rotate(board);
				go(board);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j]) ans = max(ans, board[i][j]);
			}
		}
	}
	cout << ans;
}