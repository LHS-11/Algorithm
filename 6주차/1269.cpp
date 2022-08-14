#include<bits/stdc++.h>
using namespace std;
vector<int> v1;
vector<int> v2;
int n, m, cnt, ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v1.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v2.push_back(x);
	}
	sort(v2.begin(), v2.end());
	for (auto c : v1) {
		if (lower_bound(v2.begin(), v2.end(), c) != v2.end() && c == *lower_bound(v2.begin(), v2.end(), c)) cnt++;
	}
	ans = n + m - 2 * cnt;
	cout << ans;
}