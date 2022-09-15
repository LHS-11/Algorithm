#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e16
using namespace std;
typedef long long ll;
ll t,n, cnt;
vector<ll> v, v1;
ll ans = INF;
bool go(int k) {

	cnt = 0;

	for (int i = 0; i < n - 1; i++) {
		if (k == v1[i]) continue;
		else if (k > v1[i]) return true;

		cnt += 2*(v1[i] - k);
		v1[i + 1] -= (v1[i] - k);
		v1[i] = k;
		//cout << k << ' ' << v1[i] << ' ' << v1[i + 1] << endl;
	}
	if (v1[n - 1] == k) ans = min(ans, cnt);

	if (v1[n - 1] < k) return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--) {
		ans = INF;

		cin >> n;

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		int l = 0, r = v[0];
		while (l <= r) {

			v1.assign(v.begin(), v.end());

			int m = (l + r) >> 1;

			if (go(m)) r = m - 1;
			else l = m + 1;

			v1.clear();
		}
		if (ans == INF) cout << -1 << '\n';
		else cout << ans << '\n';
		v.clear();
	}
}