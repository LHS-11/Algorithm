#include<bits/stdc++.h>
using namespace std;
#define INF 1e10
int n, m;
long long ans = INF;
int arr[100004];
bool go(long long k) {
	long long sum = 0, cnt = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum > k) {
			sum -= arr[i];
			mx = max(mx, sum);
			sum = arr[i];
			cnt++;
		}
	}
	cnt++;
	return k >= mx && cnt <= m;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	long long l = 1, r = INF, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		
		if (go(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}