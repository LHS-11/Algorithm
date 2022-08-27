#include<bits/stdc++.h>
using namespace std;
double a, b;
double dp[20][20][20];
bool isPrime(int k) {

	if (k == 1) return false;
	if (k == 2) return true;
	if (k % 2 == 0) return false;
	for (int i = 2; i * i <= k; i++) {
		if (k % i == 0) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> a >> b;

	a /= 100; b /= 100;

	dp[0][0][0] = (1 - a) * (1 - b);
	dp[0][1][0] = a * (1 - b);
	dp[0][0][1] = (1 - a) * b;
	dp[0][1][1] = a * b;


	for (int i = 1; i <= 17; i++) {
		for (int j = 0; j <= 18; j++) {
			for (int k = 0; k <= 18; k++) {

				if (j >= 1 && k >= 1) dp[i][j][k] += dp[i - 1][j - 1][k - 1] * a * b;

				if (j >= 1) dp[i][j][k] += dp[i - 1][j - 1][k] * a * (1 - b);

				if (k >= 1) dp[i][j][k] += dp[i - 1][j][k - 1] * (1 - a) * b;

				dp[i][j][k] += dp[i - 1][j][k] * (1 - a) * (1 - b);

			}
		}
	}

	double sum = 0;
	for (int i = 0; i <= 18; i++) {
		for (int j = 0; j <= 18; j++) {
			if (!isPrime(i) && !isPrime(j)) {
				sum += dp[17][i][j];
			}

		}
	}
	printf("%.6lf", 1 - sum);
}