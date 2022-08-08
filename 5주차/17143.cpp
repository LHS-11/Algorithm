#include<bits/stdc++.h>
using namespace std;
int r, c, m; // 세로, 가로, 상어의 수 
int a[104][104];
int a1[104][104];
int ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
vector <tuple<int, int, int, int, int>> shk;
vector<tuple<int, int, int, int, int>>shk1;
void go1(int y, int x, int s, int d, int z, int cnt) { // 상어가 이동

	int nx, ny,ns=s;
	while (1) {
		nx = x + ns*dx[d];
		ny = y + ns*dy[d];
		if (nx <= c && ny <= r && nx >= 1 && ny >= 1) break;
		if (d == 0 && ny < 1) {
			ns = ns - y + 1;
			y = 1;
			d = 1;
		}
		else if (d == 1 && ny > r) {
			ns = ns + y - r;
			y = r;
			d = 0;
		}
		else if (d == 2 && nx > c) {
			ns=ns+x-c;
			x = c;
			d = 3;
		}
		else if (d == 3 && nx < 1) {
			ns = ns - x + 1;
			x = 1;
			d = 2;
		}
	}
	shk1.push_back({ ny,nx,s,d,z });

}
void go2() { // 상어가 같은 장소에 있다면 잡아먹음
	sort(shk1.begin(), shk1.end());
	for (int i = 0; i < shk1.size(); i++) {
		int x, y, s, d, sz;
		tie(y, x, s, d, sz) = shk1[i];
		if (a1[y][x] < sz) {
			a1[y][x] = sz;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		a[r][c] = z;
		shk.push_back({ r,c,s,d - 1,z });
	}
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) { // 낚시왕이 상어를 잡음
			if (a[j][i]) {
				ans += a[j][i];
				a[j][i] = 0;
				break;
			}
		}
		for (int k = 0; k < shk.size(); k++) {
			int r, c, s, d, z;
			tie(r, c, s, d, z) = shk[k];
			if (a[r][c]==z) { // 잡아먹은 상어를 다시 이동시키지 않기 위해서 (상어 죽임)
				go1(r, c, s, d, z, 0);
			}
		}
		go2();
		shk.clear();
		for (int i = 0; i < shk1.size(); i++) shk.push_back(shk1[i]);
		shk1.clear();
		memcpy(a, a1, sizeof(a1));
		memset(a1, 0, sizeof(a1));
	}
	cout << ans;
}
