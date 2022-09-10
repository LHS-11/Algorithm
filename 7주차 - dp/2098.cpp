#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int n, a[17][17];
int dp[17][1<<16];
int dfs(int now, int bit) {

	if (bit == (1 << n) - 1) {
		return a[now][0] ? a[now][0] : INF;
	}

	int& ans = dp[now][bit];
	if (ans != -1) return ans;
	 
	ans = INF; // ans의 최솟값을 갱신해야 하기 때문에 (INF)
	for (int i = 0; i < n; i++) {
		if (!a[now][i]) continue;
		if (!(bit & (1 << i))) {
			ans = min(ans, dfs(i, bit | (1 << i)) + a[now][i]);
		}
	}
	return ans;

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	memset(dp, -1, sizeof(dp));
	cout<<dfs(0, 1);
}