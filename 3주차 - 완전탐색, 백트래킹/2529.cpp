#include<bits/stdc++.h>
using namespace std;
int k;
vector<char> oper;
vector<int> num;
int vis[10];
vector<string> ans;
void go(int n) { // 순열 문제 ( 모든 경우의 수 탐색 )
	if (n == k + 1) {
		int flag = 0;
		for (int i = 0; i < num.size() - 1; i++) {

				if (oper[i] == '<') {
					if (num[i] > num[i + 1]) {
						flag = 1; break;
					}
				}
				else {
					if (num[i] < num[i + 1]) {
						flag = 1; break;
					}
				}
				if (flag) break;
		}
		if (!flag) {
			string s = "";
			for (auto c : num) s += to_string(c);
			ans.push_back(s);
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		num.push_back(i);
		go(n + 1);
		num.pop_back();
		vis[i] = 0;
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k;

	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		oper.push_back(c);
	}
	go(0);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << '\n' << ans[0];
}