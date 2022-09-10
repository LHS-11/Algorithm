#include<bits/stdc++.h>
using namespace std;
int t, dp[10004];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	dp[0] = 1;
	for (int i = 1; i <= 3; i++) {
		for (int j = i; j <= 10000; j++) {
			dp[j] += dp[j - i];
		}
	}
	while (t--) {
		int x;
		cin >> x;
		cout << dp[x] << '\n';
	}
}