#include<bits/stdc++.h>
using namespace std;
int n, a[1004], cnt[1004];
int ans=1;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	cnt[0]=1;
	for (int i = 1; i < n; i++) {
		int k = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				k = max(k, cnt[j]);
			}
		}
		cnt[i] = k + 1;
		ans = max(ans, cnt[i]);
	}
	cout << ans;
}