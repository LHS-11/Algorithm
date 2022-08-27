#include<bits/stdc++.h>
using namespace std;
int n, a[2004], m;
int dp[2004][2004];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;

	//for (int i = 1; i <= n; i++) { // 짝수개
	//	dp[i][i] = 1;
	//	if (a[i] == a[i + 1]) dp[i][i + 1] = 1;
	//	int cnt = 1;
	//	while (i - cnt > 0 && i + 1 + cnt <= n) { 
	//		if (a[i - cnt] == a[i + 1 + cnt] && dp[i - cnt + 1][i + cnt ]) 	dp[i - cnt][i + 1 + cnt] = 1;
	//		cnt++;
	//	}
	//}
	//
	//for (int i = 1; i <= n; i++) { // 홀수개
	//	int cnt = 1;
	//	while (i - cnt > 0 && i + cnt <= n) {
	//		if (a[i - cnt] == a[i + cnt] && dp[i - cnt + 1][i + cnt - 1]) dp[i - cnt][i + cnt] = 1;
	//		cnt++;
	//	}
	//}
	

	// 깔끔한 풀이 => 구간의 차이를 2부터 정해서 늘려나가는 식의 dp 
	for (int i = 1; i <= n; i++) dp[i][i] = 1;

	for (int i = 1; i < n; i++) 
		if (a[i] == a[i + 1]) dp[i][i + 1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (a[j] == a[j + i] && dp[j + 1][j + i - 1]) dp[j][j + i] = 1;
		}
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}

}