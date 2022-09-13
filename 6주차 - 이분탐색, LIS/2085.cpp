#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e10
ll n, m, ans = 0;
vector<int> v;
bool go(ll k) { // 자르는 높이

	ll sum = 0;
	for (auto c : v) {
		if (c > k) sum += (c - k);
	}
	if (sum < m) {
		return true;
	}
	else {
		ans = max(ans, k);
		return false;
	}
}
int main() { // 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	ll l = 1, r = INF;

	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (go(mid)) r = mid - 1;
		else l = mid + 1;
	}

	cout << ans;
}