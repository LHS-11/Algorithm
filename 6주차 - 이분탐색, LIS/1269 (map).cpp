#include<bits/stdc++.h>
using namespace std;
int n, m, cnt, ans;
map<int,int> mp;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (mp[x]) cnt++;
	}
	ans = n + m - 2 * cnt;
	cout << ans;
}