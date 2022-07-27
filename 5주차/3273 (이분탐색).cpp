#include<bits/stdc++.h>
using namespace std;
int n, x, cnt;
vector<int> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x; v.push_back(x);
	}
	cin >> x;
	sort(v.begin(), v.end());
	for (int st = 0; st < n; st++) {
		if (v.begin() + st + 1 == v.end()) break;
		if (*lower_bound(v.begin() + st + 1, v.end(), x - v[st]) + v[st] == x) cnt++;
	}
	cout << cnt;
}