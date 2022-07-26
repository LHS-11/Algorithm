#include <bits/stdc++.h>
using namespace std;
int r, c; // r 세로, c 가로
string s[21];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ans;
void go(int x, int y, int bit, int cnt) {
	ans = max(cnt, ans);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
		if (!(bit & (1 << s[ny][nx] - 'a'))) {
			go(nx, ny, bit | (1 << s[ny][nx] - 'a'), cnt + 1);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> s[i];
	}
	go(0, 0, 1 << (s[0][0] - 'a'), 1);
	cout << ans;
}