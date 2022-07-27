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
	int en = v.size() - 1;
	for (int st = 0; st < n; st++) {
		while ( st < en && v[st] + v[en] != x) {
			if (v[st] + v[en] < x) break;
			en--;
		}
        if (st >= en) break;
		if (v[st] + v[en] == x) cnt++;
	}
	cout << cnt;
}
