#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> c;
vector<int>k;
int vis[9];
void combi(int start) {
	if (c.size() == 7) {
		int sum = 100;
		for (int i = 0; i < 7; i++) {
			sum -= c[i];
		}
		if (sum == 0) {
			k = c;
		}
		return;
	}
	for (int i = start; i < 9; i++) {
		if (vis[i]) continue;
		c.push_back(v[i]);
		vis[i] = 1;
		combi(i + 1);
		vis[i] = 0;
		c.pop_back();
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	combi(0);

	for (int i = 0; i < 7; i++) cout << k[i] << '\n';
}
