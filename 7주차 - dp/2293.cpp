#include<bits/stdc++.h>
using namespace std;
int n, k, dp[10004];
vector<int> v;
int go(int num) { // top-down 방식  => 이 문제에서는 메모리 초과가 남, bottom-up 방식으로 무조건 풀어야함
	if (num == 0) return 1;
	
	int& ans = dp[num];
	if (ans) return ans;

	for (auto c : v) {
		if (num >= c) return ans += go(num - c);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	dp[0] = 1;
	for (int i = 0; i < n; i++) { // bottom-up 방식
		for (int j = v[i]; j <= k; j++) {
			dp[j] += dp[j - v[i]]; // 처음에 v[0]으로 만들 수 있는 경우를 dp[j]에 쌓고, 그 다음에 v[1]을 추가함으로써 만들 수 있는 경우를 dp값에 또 누적한다.
		}
	}
	cout << dp[k];
}