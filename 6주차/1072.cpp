#include<bits/stdc++.h>
#define INF 1e13
using namespace std;
long long x, y, z;
bool go(int k) {

	if ((int)z < (int)((y + k)*100 / (x + k))) {
		return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> x >> y;
	long long l = 1, r = INF, m;
	long long ans = INF;
	z = y * 100 / x;
	while (l <= r) {
		m = (l + r) >> 1;
		if (go(m)) {
			ans = min(ans, m);
			r = m - 1;
		}
		else l = m + 1;
	}
	if (ans == INF) cout << -1;
	else cout << ans;
	
}