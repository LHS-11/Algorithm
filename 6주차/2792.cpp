#include<bits/stdc++.h>
using namespace std;
#define INF 1e10;
int n, m;
long long ans = INF;
vector<int> v;
long long go(int k) {
	long long sum = 0;
	for (auto c : v) {
		int x = c;
		x% k == 0 ? sum += (x / k) : sum += (x / k) + 1;
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	long long l = 1, mid, r = INF;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (n >= go(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans<<'\n';
}
