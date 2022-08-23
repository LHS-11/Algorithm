#include<bits/stdc++.h>
using namespace std;
int n;
double m;
int dp[10004];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (n != 0) {

		vector<pair<int, int>>v;
		for (int i = 0; i < n; i++) {
			int a; double b;
			cin >> a >> b;
			int cost = b * 100 + 0.5; // 부동소수점에서 오차가 나기 때문에 적당한 작은 수를 더해서 소숫점 아래에서 버림해도 문제가 없도록 함
			v.push_back({ cost,a });
		}
		fill(dp, dp + 10004, 0);
		sort(v.begin(), v.end());
		int m1 = m * 100 + 0.5;
		for (int i = 0; i < n; i++) {
			for (int j = v[i].first; j <= m1; j++) {
				dp[j] = max(dp[j - v[i].first] + v[i].second, dp[j]);
			}
		}
		cout << dp[m1] << '\n';
		cin >> n >> m;
	}
}