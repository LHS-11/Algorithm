#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
stack<int> stk;
int vis[200001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >>n>> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			stk.push(i);
		}
		else {
			if (!stk.empty()) {
				vis[stk.top()] = 1;
				vis[i] = 1;
				stk.pop();
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (vis[i]) cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	ans = max(ans, cnt);
	cout << ans;
}