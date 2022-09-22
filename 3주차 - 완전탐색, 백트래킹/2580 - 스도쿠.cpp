#include<bits/stdc++.h>
using namespace std;
int board[10][10],chk[10], k,flag;
vector<pair<int, int>>v;
bool check1(int x, int y,int t) { // 가로 체크
	
	int chk[10];
	memset(chk, 0, sizeof(chk));
	for (int i = 0; i < 9; i++) {
		chk[board[y][i]]++;
	}

	if (!chk[t]) return true;
	return false;

}
bool check2(int x, int y,int t) { // 세로 체크
	
	int chk[10];
	memset(chk, 0, sizeof(chk));

	for (int i = 0; i < 9; i++) {
		chk[board[i][x]]++;
	}


	if (!chk[t]) return true;
	return false;
}
bool check(int x, int y,int t) { // 3 x 3 행렬 확인
	int nx = x / 3; // 0
	int ny = y / 3; // 2

	int chk[10];
	memset(chk, 0, sizeof(chk));
	for (int i = ny * 3; i < ny*3 + 3; i++) {
		for (int j = nx * 3; j< nx*3 + 3; j++) {
			chk[board[i][j]]++;
		}
	}

	if (!chk[t]) return true;
	return false;

}
void go(int n) {

	if (n == k) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0); // 함수를 바로 종료
	}

	for (int i = 1; i < 10; i++) {
		if (check(v[n].first, v[n].second,i) && check1(v[n].first, v[n].second,i) && check2(v[n].first, v[n].second,i)) {
			board[v[n].second][v[n].first] = i;
			go(n + 1);
			board[v[n].second][v[n].first] = 0;
		}
	}
	return;

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (!board[i][j]) {
				k++;
				v.push_back({ j,i });
			}
		}
	}
	go(0);
}