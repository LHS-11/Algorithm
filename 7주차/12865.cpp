#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
vector<pair<int, int>> v;
int dp[100004];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= v[i].first; j--) { // 무게를 기준으로
			dp[j] = max(dp[j - v[i].first] + v[i].second, dp[j]);
		}
	}
	cout << dp[k];
}