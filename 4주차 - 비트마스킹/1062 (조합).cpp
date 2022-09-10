#include<bits/stdc++.h>
using namespace std;
int n, k;
string s[51];
int chk[26], vis[26], ans;
void go(int idx, int cnt) {
	if (k - 5 == cnt) {
		int rst = 0;
		for (int i = 0; i < n; i++) {
			int flag = 0;
			for (auto c : s[i]) {
				if (!chk[c - 'a']) {
					flag = 1;
					break;
				}
			}
			if (!flag) rst++;
		}
		ans = max(ans, rst);
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (chk[i]) continue;
		chk[i] = 1;
		go(i, cnt + 1);
		chk[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	chk['a' - 'a']++; 
	chk['n' - 'a']++;
	chk['t' - 'a']++;
	chk['i' - 'a']++;
	chk['c' - 'a']++;

	if (k < 5) cout << 0;
	else {
		go(0, 0);
		cout << ans;
	}

}