#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int oper[4];
vector<int> op;
vector<int> op1;
int ans1 = -1987654321;
int ans2 = 1987654321;
int vis[15];
void go(int sz) {
	if (sz == n-1) {
		int sum = v[0];
		for (int i = 0; i < n - 1;i++) {
			if (op1[i] == 0) {
				sum +=  v[i+1];
			}
			else if (op1[i] == 1) {
				sum  -= v[i+1];

			}
			else if (op1[i] == 2) {
				sum *= v[i+1];

			}
			else {
				sum /= v[i+1];

			}
		}
		ans1 = max(ans1, sum);
		ans2 = min(ans2, sum);
		return;
	}
	for (int i = 0; i < n-1; i++) {
		if (vis[i]) continue;
		op1.push_back(op[i]);
		vis[i] = 1;
		go(sz + 1);
		vis[i] = 0;
		op1.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) op.push_back(i);
	}
	go(0);
	cout << ans1 << '\n' << ans2;
}