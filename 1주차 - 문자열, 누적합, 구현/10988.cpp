#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin >> s;
	
	string s1 = s;

	reverse(s.begin(), s.end());

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s1[i]) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}
