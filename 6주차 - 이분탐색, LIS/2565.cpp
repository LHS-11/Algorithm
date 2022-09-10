#include<bits/stdc++.h>
using namespace std;
int n, cnt[104], ans = 1;
int lis[104], len;
vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	/*sort(v.begin(), v.end());  O(n^2) 풀이
	cnt[0] = 1;
	for (int i = 1; i < n; i++) {
		int k = 0;
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				k = max(k, cnt[j]);
			}
		}
		cnt[i] = k + 1;
		ans = max(ans, cnt[i]);
	}
	cout << n - ans;*/
	for (int i = 0; i < n; i++) { // O(nlogn) 풀이 
		auto idx = lower_bound(lis, lis + len, v[i].second);
		if (*idx == 0) len++;
		*idx = v[i].second;
	}
	cout << n - len;
}