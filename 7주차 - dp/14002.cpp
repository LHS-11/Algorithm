#include<bits/stdc++.h>
using namespace std;
int n, idx, a[1004], cnt[1004], b[1004], ans = 1;
vector<int> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cnt[0] = 1;
	fill(b, b + n, -1);
	for (int i = 1; i < n; i++) {
		int k = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				if (k < cnt[j]) {
					k = cnt[j];
					b[i] = j;
				}
			}
		}
		cnt[i] = k + 1;
		if (ans < cnt[i]) {
			ans = cnt[i];
			idx = i;
		}
	}
	cout << ans << '\n';
	for (; idx != -1; idx = b[idx]) {
		v.push_back(a[idx]);
	}
	for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << ' ';
}