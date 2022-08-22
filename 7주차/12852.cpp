#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int n;
int dp[1000004];
int pre[1000004];
void go(int k) {
	if (k == 0) return;
	cout << k << ' ';
	if (k % 3 == 0 && dp[k] == dp[k / 3] + 1) go(k / 3);
	if (k % 2 == 0 && dp[k] == dp[k / 2] + 1) go(k / 2);
	if (k - 1 >= 0 && dp[k] == dp[k - 1] + 1) go(k - 1);
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	fill(dp, dp + n+1, INF);
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) {
			pre[i] = i / 3;
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) pre[i] = i / 2;
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		if (dp[i] > dp[i - 1] + 1) pre[i] = i - 1;
		dp[i] = min(dp[i - 1] + 1, dp[i]);
	}
	cout << dp[n] << '\n';
	//go(n);
	while (n != 1) {
		cout << n<<' ';
		n = pre[n];
	}
	cout << 1 << ' ';
}