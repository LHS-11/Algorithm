#include<bits/stdc++.h>
using namespace std;
int n;
int v1[21],v2[21],dp[101];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v1[i];
	for (int i = 0; i < n; i++) cin >> v2[i];

	for (int i = 0; i < n; i++) {
		for (int j = 99; j >= v1[i]; j--) {
			dp[j] = max(dp[j - v1[i]] + v2[i], dp[j]);
		}
	}
	cout << dp[99];
}