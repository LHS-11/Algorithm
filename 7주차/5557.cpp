#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[104];
ll dp[104][21];
ll go(int idx,int sum) {

	if (idx == n - 1) {
		if (a[idx] == sum) return 1;
		else return 0;
	}

	if (sum < 0 || sum>20) return 0;

	ll& ans = dp[idx][sum];
	if (ans) return ans;

	ans += go(idx + 1, sum + a[idx]);
	ans += go(idx + 1, sum - a[idx]);
	return ans;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	//memset(dp, -1, sizeof(dp));
	cout << go(0, 0);
}