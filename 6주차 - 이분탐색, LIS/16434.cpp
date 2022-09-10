#include<bits/stdc++.h>>
using namespace std;
typedef long long ll;
#define INF 1e18
ll n, atk;
ll ans;
vector<tuple<ll, ll, ll>>v;
bool go(ll k) {
	ll attack = atk;
	ll hp = k;
	for (int i = 0; i < n; i++) {
		ll info, atk1, h;
		tie(info, atk1, h) = v[i];
		ll cnt = 0;
		if (info == 1) {
			(h % attack) != 0 ? cnt = h / attack + 1 : cnt = h / attack;
			cnt--;
			if (cnt * atk1 >= hp) return false;
			hp -= cnt * atk1;
		}
		else {
			attack += atk1;
			hp = min(k, hp + h);
			//hp = min(k, hp);
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> atk;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	ll l = 1, r = INF, m;
	while (l <= r) {
		m = (l + r) >> 1;
		if (go(m)) {
			ans = m;
			r = m - 1;
		}
		else  l = m + 1;
	}
	cout << ans;
}