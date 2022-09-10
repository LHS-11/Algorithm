#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<char> prv;
vector<char> nxt;
int chk[104];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;

	int flag = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*') {
			flag = 1;
			continue;
		}
		if (flag) {
			nxt.push_back(s[i]);
		}
		else {
			prv.push_back(s[i]);
		}
	}

	while (n--) {
		int flag1 = 0;
		string s1;
		cin >> s1;
		for (int i = 0; i < prv.size(); i++) {
			if (s1[i] != prv[i]) {
				flag1 = 1;
				break;
			}
			chk[i]++;
		}
		if (!flag1) {	
			int idxN = 0;
			for (int i = nxt.size() - 1; i >= 0; i--) {
				if (s1[s1.size() - 1 - idxN] != nxt[i] || chk[s1.size()-1-idxN]) {
					flag1 = 1;
					break;
				}
				idxN++;
			}
		}
		if (flag1) cout << "NE" << '\n';
		else cout << "DA" << '\n';
		memset(chk, 0, sizeof(chk));
	}
}
