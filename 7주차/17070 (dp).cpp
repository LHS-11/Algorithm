#include<bits/stdc++.h>
using namespace std;
int n, a[17][17];
int dp[17][17][3];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}

	for (int i = 1; i < n; i++) {
		if (a[0][i]) break;
		dp[0][i][0] = 1; // dp[세로][가로][방향]
	}
	 
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (a[i][j]) continue;
			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2]; // 가로
			dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2]; // 세로
			if (!a[i-1][j] && !a[i][j-1]) dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]; // 대각선
		}
	}
	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}