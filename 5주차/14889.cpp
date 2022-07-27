#include<bits/stdc++.h>
using namespace std;
int n;
int a[21][21];
int vis[21];
int ans = 987654321;
void go(int idx, int sz) {
	if (sz == n / 2) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) { // vis 배열로 같은 팀 유무 파악
			for (int j = 0; j < n; j++) {
				if (vis[i] && vis[j]) {
					sum1 += a[i][j];
				}
				else if (!vis[i] && !vis[j]) {
					sum2 += a[i][j];
				}
			}
		}
		ans = min(ans, abs(sum1 - sum2));
	}
	for (int i = idx; i < n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		go(i, sz + 1);
		vis[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	go(0, 0);
	cout << ans;
}