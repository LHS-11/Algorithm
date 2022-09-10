#include<bits/stdc++.h>
using namespace std;
string s;
int dp[2504][2504], dp2[2504];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> s;

	for (int i = 0; i < s.size(); i++) { // dp[idx1][idx2] => idx1 번부터 idx2번 까지 펠린드롬이면 1
		dp[i][i] = 1;
		if (i<=s.size()-2 && s[i] == s[i + 1]) dp[i][i + 1] = 1;
	}

	for (int i = 2; i < s.size(); i++) {
		for (int j = 0; j < s.size() - i; j++) {
			if (s[j] == s[j + i] && dp[j + 1][j + i - 1]) dp[j][j + i] = 1;
		}
	}


	for (int i = 0; i < s.size(); i++) { // dp2[idx] => idx까지의 최소 분할 갯수
		dp2[i] = 1e9;
		for (int j = 0; j <= i; j++) {
			if (dp[j][i]) {
				if (j == 0) dp2[i] = 1;
				else dp2[i] = min(dp2[i], dp2[j - 1] + 1);
			}
		}
		//cout << i<<' '<<dp2[i] << endl;
	}
	cout << dp2[s.size() - 1];

}