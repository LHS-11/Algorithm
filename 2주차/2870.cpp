#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	vector<string> v;
	while (n--) {
		string s;
		cin >> s;

		string s1 = "";
		for (int i = 0;i<s.size();i++) {
			if (!(s[i] >= 'a' && s[i] <= 'z')) {
				s1 += s[i];
				if (i ==s.size() - 1) {
					if(!s1.empty())
						v.push_back(s1);
					s1 = "";
					}
				}
			else {
				if(!s1.empty())
					v.push_back(s1);
				s1 = "";
				}
			}
	}
	vector<pair<int,string>> v1;
	for(auto c : v){
		if(c.size()!=1){
			while(c.find('0')!=string::npos && c.find('0')==0){
				c.erase(0,1);
				if(c.size()==1) break;
			}
		}
		v1.push_back({ c.size(),c });
	}
	
	sort(v1.begin(), v1.end());
	
	for (auto c : v1) cout << c.second << '\n';
}
