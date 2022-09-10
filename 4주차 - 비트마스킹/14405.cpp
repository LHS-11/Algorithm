#include<bits/stdc++.h>
using namespace std;
string s;
int vis[5001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;

	int flag = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i < s.size() - 1 && (s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka")) i++;
		else if (i < s.size() - 2 && s.substr(i, 3) == "chu") i += 2;
		else flag = 1;
	}
	if (flag) cout << "NO";
	else cout << "YES";
}
// 밑에는 처음 푼 코드 최적화 X
/* 
#include<bits/stdc++.h>
using namespace std;
string s;
int vis[5001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;

	int flag = 0;
	for (int i = 0; i < s.size()-1; i++) {
		if (vis[i]) continue;
		if (s[i] == 'p') {
			if (s[i + 1] == 'i') {
				vis[i] = 1; vis[i + 1] = 1;
			}
			else {
				flag = 1; break;
			}
		}
		else if (s[i] == 'k') {
			if (s[i + 1] == 'a') {
				vis[i] = 1; vis[i + 1] = 1;
			}
			else {
				flag = 1; break;
			}
		}
		else if (s[i] == 'c') {
			if (s[i + 1] == 'h') {
				if (i + 2 == s.size()) {
					flag = 1; break;
				}
				if (s[i + 2] == 'u') {
					vis[i] = 1; vis[i + 1] = 1; vis[i + 2] = 1;
				}
				else {
					flag = 1; break;
				}
			}
			else {
				flag = 1; break;
			}
		}
		else {
			flag = 1; break;
		}
	}
	if (flag || !vis[s.size()-1]) cout << "NO";
	else cout << "YES";
}*/