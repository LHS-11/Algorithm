#include<bits/stdc++.h>
using namespace std;
int chk[26];
int n;
int main() {
	cin >> n;
	string ans = "";
	while (n--) {
		string s;
		cin >> s;
		chk[s[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (chk[i] >= 5) ans += (i + 'a');
	}

	if (ans != "") cout << ans;
	else cout << "PREDAJA";
	return 0;
}
