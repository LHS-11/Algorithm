#include<bits/stdc++.h>
using namespace std;
int dx[4] = { 1,0,-1,0 }; // 동 남 서 북 
int dy[4] = { 0,1,0,-1 };
int n, a[101][101];
int k, l, ans;
int vis[101][101];
map<int, char>mp;
int go(int now, char d) {
	if (d == 'D') {
		now += 1;
		now %= 4;
	}
	else if (d == 'L') {
		now -= 1;
		if (now < 0) now = 3;
	}
	return now;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y; // 행 : 세로, 열 : 가로
		a[x - 1][y - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char y;
		cin >> x >> y;
		mp.insert({ x,y });
	}

	deque<tuple<int, int, int, int>> q;
	q.push_back({ 0,0,0,0 });
	while (!q.empty()) {
		int y, x, dir, t;
		tie(y, x, dir, t) = q.front();
		if (mp[t]) dir = go(dir, mp[t]);
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || vis[ny][nx]) {
			ans = t + 1;
			break;
		}
		if (!a[ny][nx]) {
			int by, bx, bdir, bt;
			tie(by, bx, bdir, bt) = q.back();
			vis[by][bx] = 0;
			q.pop_back();
		}
		else a[ny][nx] = 0;
		vis[ny][nx] = 1;
		q.push_front({ ny,nx,dir,t + 1 });
	}
	cout << ans;
}