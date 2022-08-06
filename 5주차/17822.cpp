#include<bits/stdc++.h>
using namespace std;
int n, m, t;
int a[54][54];
void rotateR(int k,int cnt) { // 시계 방향으로 회전

	for (int i = k; i <= n; i += k) {
		for (int j = 0; j < cnt; j++) {
			int tmp = a[i][m];
			for (int t = m; t >= 2; t--) {
				a[i][t] = a[i][t - 1]; 
			}
			a[i][1] = tmp;
		}
	}
}
void rotateL(int k, int cnt) { // 반시계 방향으로 회전
	
	for (int i = k; i <= n; i += k) {
		for (int j = 0; j < cnt; j++) {
			int tmp = a[i][1];
			for (int t = 1; t <= m-1; t++) {
				a[i][t] = a[i][t + 1]; 
			}
			a[i][m] = tmp;
		}
	}
}
void check() {

	vector<pair<int, int>> v;
	double sum = 0; double cnt = 0;

	for (int i = 1; i <= n; i++) { // 가로 방향
		for (int j = 1; j <= m; j++) {
			if (j<m && a[i][j]&&a[i][j] == a[i][j + 1]) {
				v.push_back({ i,j });
				v.push_back({ i,j + 1 });
			}
			if (j == m && a[i][m] && a[i][1] == a[i][m]) { // 원형큐 형태라서 첫번째 인덱스와 m번째 인덱스를 비교해야함
				v.push_back({ i,m });
				v.push_back({ i,1 });
			}
			if (a[i][j]) cnt++;
			sum += a[i][j];
		}
	}
	
	for (int i = 1; i <= m; i++) { // 세로 방향
		for (int j = 1; j <= n - 1; j++) {
			if (a[j][i]&& a[j][i] == a[j + 1][i]) {
				v.push_back({ j,i });
				v.push_back({ j + 1,i });
			}
		}
	}
	
	if (v.size()) {
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].second;
			int y = v[i].first;
			a[y][x] = 0;
		}
	}
	else {
		double avg = sum / cnt;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j]) {
					if (avg < a[i][j]) {
						a[i][j]--;
					}
					else if (avg > a[i][j]) {
						a[i][j]++;
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;
		if (d == 0) rotateR(x, k);
		else rotateL(x, k);
		check();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) ans += a[i][j];
		}
	}
	cout << ans;
}