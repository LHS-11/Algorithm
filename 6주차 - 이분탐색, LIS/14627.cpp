#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
int s, c;
long long sum;
map<int, int> mp;
int a[1000004];
bool go(long long k) {
	long long cnt = 0;
	for (int i = 0; i < s; i++) {
		cnt += (a[i]/k); // cnt가 작다면 k가 크다는 것 => k를 줄여서 cnt를 키워야함
	}
	return cnt < c;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> c;
	for (int i = 0; i < s; i++) {
		cin >> a[i];
		sum += a[i];
	}

	long long l = 0, r = INF, m;
	long long ans;
	while (l <= r) {
		m = (l + r) >> 1;
		if (go(m)) {
			r = m - 1;
		}
		else {
			ans = m;
			l = m + 1;
		}
	}
	cout << sum - (ans * c);
}