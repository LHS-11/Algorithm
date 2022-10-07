#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int dp[1000004][3][2], n,vis[31],flag;
vector<int> v, s;
vector<string> ans;
void go(int k,int sz) {
	if (k == sz) {
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < sz; i++) {
			if (v[i] == 1) {
				cnt1++;
				if (cnt1 >= 2) return;
				cnt2 = 0;
			}
			else {
				cnt2++;
				if (cnt2 >= 3) return;
				cnt1 = 0;
			}
		}
		string str = "";
		for (int i = 0; i < sz; i++) {
			str += to_string(v[i]);
		}
		ans.push_back(str);
		return;
	}

	flag = -1;
	for (int i = 0; i < sz; i++) {
		if (vis[i] || flag == s[i]) continue;
		vis[i] = 1;
		v.push_back(s[i]);
		go(k + 1, sz);
		flag = s[i];
		v.pop_back();
		vis[i] = 0;
	}
}
int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	dp[0][0][1] = 1;
	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j <= 2; j++) { // 세로 타일 확인
			if (j == 1) {
				if (i - 1 == 0) dp[i][j][0] = 1;
				else dp[i][j][0] = dp[i - 1][j - 1][1];
			}
			else {
				if(i>=j)
				dp[i][j][0] =dp[i - 1][j - 1][0];
			}
		}

		if (i - 2 > 0) {
			dp[i][0][1] = (dp[i - 2][1][0] + dp[i - 2][2][0])% 20201212;
		}
		else if (i - 2 == 0) {
			dp[i][0][1] = 1;
		}

	}

	cout << (dp[n][1][0] + dp[n][2][0] + dp[n][0][1]) % 20201212 << endl;


	if (n <= 30) {
		for (int i = 0; i <= 30; i++) {
			for (int j = 0; j <= 15; j++) {
				if (i + 2 * j == n) {
					for (int k = 0; k < j; k++) {
						s.push_back(1);
					}

					for (int k = 0; k < i; k++) {
						s.push_back(0);
					}
					go(0, i + j);
				}
				s.clear();
			}
		}
		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				if (ans[i][j] == '1') cout << "==";
				else cout << '|';
			}
			cout << endl;
		}
	}



}