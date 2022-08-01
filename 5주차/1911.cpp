#include<bits/stdc++.h>
using namespace std;
int n, l,ans;
vector < pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int now = 0;
	for (auto c : v) {
		if (now >= c.second) continue;
		if (now < c.first) {
			int t = c.second - c.first;
			t% l != 0 ? t = t / l + 1 : t = t / l;
			now = c.first + t * l;
			ans += t;
		}
		else {
			int t = c.second - now;
			t% l != 0 ? t = t / l + 1 : t = t / l;
			now += t * l;
			ans += t;
		}
	}
	cout << ans;
}