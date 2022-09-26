#include<iostream>
using namespace std;
int dp[100004][4];
int n;
int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {

			if (j == 1) {
				if (i - 1 == 0) dp[i][j] = 1;
				else {
					dp[i][j] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
				}
			}
			else if (j == 2) {
				if (i - 2 == 0) dp[i][j] = 1;
				else {
					dp[i][j] = dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3];
				}
			}
			else if (j == 3) {

				if (i - 3 == 0) dp[i][j] = 1;
				else {
					dp[i][j] = dp[i - 3][1] + dp[i - 3][2];
				}
			}
			dp[i][j] %= 1004;
		}
	}
	cout << (dp[n][1] + dp[n][2] + dp[n][3])%1004;

}
