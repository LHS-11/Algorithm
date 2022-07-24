#include<bits/stdc++.h>
using namespace std;
int n, k;
int words[51];
int alp, ans;
void go(int idx, int cnt) {
	if (cnt == k - 5) {
		int rst = 0;
		for (int i = 0; i < n;i++) {
			if ((words[i] & alp) == words[i]) rst++;
		}
		ans = max(ans, rst);
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alp & (1 << i)) continue;
		alp |= (1 << i);
		go(i, cnt + 1);
		alp &= ~(1 << i);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (auto c : s) {
			words[i] |= (1 << (c - 'a'));
		}
	}
	alp |= (1 << ('a' - 'a'));
	alp |= (1 << ('n' - 'a'));
	alp |= (1 << ('t' - 'a'));
	alp |= (1 << ('i' - 'a'));
	alp |= (1 << ('c' - 'a'));
	if (k < 5) cout << 0;
	else {
		go(0, 0);
		cout << ans;
	}
}