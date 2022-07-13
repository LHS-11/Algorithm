#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<int> num;
vector<char> oper;
int ans = -987654321;
int cal(int a, char c, int b) {
	if (c == '*') return a * b;
	else if (c == '-') return a - b;
	else return a + b;
}
void go(int idx,int rst) { // 왼쪽에서부터 누적해가면서 모든 경우의 수 탐색
	if (num.size() - 1 == idx) {
		ans = max(ans, rst);
		return;
	}
	go(idx + 1, cal(rst, oper[idx], num[idx + 1]));
	
	if(num.size()-1>=idx+2)
		go(idx + 2, cal(rst, oper[idx], cal(num[idx + 1], oper[idx + 1], num[idx + 2])));
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') num.push_back(s[i]-'0');
		else  oper.push_back(s[i]);
	}
	go(0, s[0]-'0');
	cout << ans;
}