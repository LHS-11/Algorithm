#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s1 >> s2;

	if (s1.size() > s2.size()) {
		int sz = s1.size() - s2.size();
		string s = "";
		for (int i = 0; i < sz; i++) s += '0';
		s2 = s + s2; 
	}
	else {
		int sz = s2.size() - s1.size();
		string s = "";
		for (int i = 0; i < sz; i++) s += '0';
		s1 = s + s1;
	}

	string ans = ""; int tmp = 0;
	for (int i = s1.size() - 1; i >= 0; i--) {
		int n1 = s1[i] - '0'; 
		int n2 = s2[i] - '0';
		int sum = n1 + n2+tmp;
		ans = to_string(sum % 10)+ans;
		tmp = sum / 10;
	}
	if(tmp) ans = to_string(tmp) + ans;
	cout << ans;
}