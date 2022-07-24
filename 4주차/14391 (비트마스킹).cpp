#include<bits/stdc++.h>
using namespace std;
int n, m,ans; // n : 세로, m : 가로
string s[4];
int a[4][4];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			a[i][j] = s[i][j] - 48;
		}
	}
	
	for (int i = 0; i < (1 << n * m); i++) { // 모든 경우의 수 탐색 -> 1 이 가로, 0 이 세로 

		int sum = 0;
		for (int j = 0; j < n; j++) {
			int cur = 0;
			for (int k = 0; k < m; k++) {
				int t = j * m + k;
				if (i & (1 << t)) {
					cur = cur * 10 + a[j][k];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		for (int j = 0; j < m; j++) {
			int cur = 0;
			for (int k = 0; k < n; k++) {
				int t = k * m + j;
				if (!(i & (1 << t))) {
					cur = cur * 10 + a[k][j];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;

		}
		ans = max(ans, sum);
	}
	cout << ans;
}