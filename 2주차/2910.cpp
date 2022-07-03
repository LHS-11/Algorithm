#include<bits/stdc++.h>
using namespace std;
int n, c;
vector<int> a;
vector<tuple<int, int, int>> v;
map<int, int> m;
map<int, int> chk;
bool cmp(tuple<int, int, int> &v1, tuple<int, int, int > &v2) {

	if (get<0>(v1) == get<0>(v2)) {
		return get<1>(v1) < get<1>(v2);
	}
	return get<0>(v1) > get<0>(v2);

}
int main() {
	ios::sync_with_stdio; cin.tie(0); cout.tie(0);

	cin >> n >> c;


	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
		m[x]++;
	}

	for (int i = 0; i < a.size(); i++) {
		if (chk[a[i]]) continue;
		chk[a[i]]++;
		v.push_back({ m[a[i]],i,a[i] });
	}

	sort(v.begin(), v.end(), cmp);

	for (auto c : v) {
		int x, y, z;
		tie(x, y, z) = c;

		for (int i = 0; i < x; i++) cout << z << ' ';

	}
}
