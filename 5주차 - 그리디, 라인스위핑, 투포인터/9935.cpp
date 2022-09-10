#include<bits/stdc++.h>
using namespace std;
string s;
string bomb;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> bomb;

	string ans = "";
	for (int i = 0; i < s.size(); i++) { //폭발 문자열이 ans에 들어오면 바로 삭제
		ans += s[i];
		if (ans.size() >=bomb.size() && ans.substr(ans.size()-bomb.size(), bomb.size()) == bomb) {
			ans.erase(ans.size()-bomb.size(), bomb.size());
		}
	}
	if (ans.empty()) cout << "FRULA";
	else cout << ans;
}