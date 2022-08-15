#include<bits/stdc++.h>
using namespace std;
#define INF 1e13
long long n, m;
long long a[10004];
long long ans, sum;
int rst;
bool go(long long k) {
	sum = 0;
	for (int i = 0; i < m; i++) {
		sum += (k/a[i]);
	}
	return (n-m) <= sum;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i];
	if (n <= m) { // 0분에 모든 아이가 놀이기구에 탑승할 때
		cout << n;
	}
	else {
		long long l = 1, r = INF, mid; 
		while (l <= r) { // => 시간을 기준으로 이분탐색 (1분부터~ )
			mid = (l + r) >> 1;
			if (go(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		int cnt = m;
		for (int i = 0; i < m; i++) {
			cnt += ((ans - 1) / a[i]);
		}
		for (int i = 0; i < m; i++) {
			if (ans % a[i] == 0) cnt++;
			if (cnt == n) {
				rst = i + 1;
				break;
			}
		}
		cout << rst;
	}
}