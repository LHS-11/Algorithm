#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[26];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;

	for (auto c : s) {
		cnt[c - 'A']++;
	}
	string s2 = "";
	int flag = 0;
	for (int i = 0; i < 26;i++) {
		if (cnt[i] % 2 != 0) {
			flag++;
			s2 += i + 'A';
		}
	}
	if (flag > 1) cout << "I'm Sorry Hansoo";
	else {
		string str = "";
		if (flag == 1) {
			for (int i = 25; i >= 0; i--) {
				if (cnt[i]) {
					for (int j = 0; j < cnt[i] / 2; j++) {
						string s1 = "";
						s1 += i + 'A';
						str.insert(0, s1);
					}
					for (int j = 0; j < cnt[i] / 2; j++) {
						string s1 = "";
						s1 += i + 'A';
						str.insert(str.size(), s1);
					}
				}
			}
			str.insert(str.size() / 2, s2);
		}
		else {
			for (int i = 25; i >= 0; i--) {
				if (cnt[i]) {
					for (int j = 0; j < cnt[i] / 2; j++) {
						string s1 = "";
						s1 += i + 'A';
						str.insert(0, s1);
					}
					for (int j = 0; j < cnt[i] / 2; j++) {
						string s1 = "";
						s1 += i + 'A';
						str.insert(str.size(), s1);
					}
				}
			}
		}
		cout << str;
	}

}

