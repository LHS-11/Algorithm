#include <bits/stdc++.h>
using namespace std;
int n,ans;
stack<pair<int,int>> stk;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		int cnt = 1;

		while (!stk.empty() && x >= stk.top().first) {
			ans += stk.top().second;
			if (x == stk.top().first) cnt = stk.top().second + 1; // 같은 수가 존재할 때 누적
			else cnt = 1; 
			stk.pop();
		}
		if (stk.size()) ans++; // 내림차순일때
		stk.push({ x,cnt });	
	}
	cout << ans;
}