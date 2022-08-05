#include<bits/stdc++.h>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int n;
vector<tuple<int, int, int, int>> v;
int board[104][104];
void go(int cnt,int sz,int dir,int x,int y) { // 회전변환 시계 방향으로 90도 = 반시계 방향으로 270도
	
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	vector<pair<int, int>> v1;
	v1.push_back({ nx,ny });

	if (cnt == sz) {
		return;
	}
	
}
void rotate(int baseX,int baseY,vector<pair<int,int>> v) {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		int nx = (baseY - y) + baseX;
		int ny = -(baseX-x)+baseY;
		board[ny][nx] = 1;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		v.push_back({ x,y,d,g });
	}

	
}
