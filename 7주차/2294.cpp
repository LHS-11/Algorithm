#include<bits/stdc++.h>
using namespace std;
#define INF 1e8
int n, k;
vector<int> v;
int dp[10004];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k; 
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	fill(dp, dp + 10004, INF);
	dp[0] = 0;
	sort(v.begin(), v.end());
	for (int i = 1; i <= k; i++) { // k 최대 숫자 10000, n 최대 100  => nm = 천만 
		for (auto c : v) {
			if (i >= c) {
				dp[i] = min(dp[i], dp[i-c] + 1);
			}
		}
	}
	cout << endl;
	if (dp[k] == INF) cout << -1;
	else cout << dp[k];
}