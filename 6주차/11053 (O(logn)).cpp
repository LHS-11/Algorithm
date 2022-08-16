#include<bits/stdc++.h>
using namespace std;
int n, a[1004], lis[1004], len;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n;i++) {
		auto idx = lower_bound(lis, lis + len, a[i]); // 작은거 계속해서 넣음
		if (*idx == 0) len++;
		*idx = a[i];
	}
	cout << len;
}