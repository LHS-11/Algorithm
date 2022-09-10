#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, c, a[34];
vector<ll> v1, v2; // n이 30이기 때문에 2^30 = 10억이 넘어서 vector 하나에 다 담아서 풀 수 없다. => sol) 반반씩 나눠서 완탐을 돌림
void go(int idx,int sz,vector<ll>& v,ll sum) { 
	if (sum > c) return;
	if (idx >= sz) {
		v.push_back(sum);
		return;
	}
	go(idx + 1, sz, v, sum);
	go(idx + 1, sz, v, sum + a[idx]);

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> a[i];

	go(0, n / 2, v1, 0);
	go(n / 2, n, v2, 0);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int ans = 0;
	for (auto k : v1) {
		ans += upper_bound(v2.begin(), v2.end(), c-k) - v2.begin();
	}
	cout << ans;
}