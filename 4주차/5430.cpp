#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
using namespace std;
int t;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		string s;
		int n;
		string s1;
		deque<int> dq;

		cin >> s;
		cin >> n;
		cin >> s1;

		if (n != 0) {
			string s2 = "";
			for (int i = 0; i < s1.size(); i++) {
				if (s1[i] >= '0' && s1[i] <= '9') {
					s2 += s1[i];
				}
				else if (s1[i] == ',') {
					dq.push_back(stoi(s2));
					s2 = "";
				}
				else if (s1[i] == ']') dq.push_back(stoi(s2));
			}
		}
		
		int flag = 0; // flag - > 0 처음 그대로, -> 1 한번 바뀜
		int flag1 = 0;
		for (auto c : s) {
			if (c == 'R') {
				flag == 0 ? flag = 1 : flag = 0;
			}
			else {
				if (dq.empty()) {
					flag1 = 1;
					break;
				}
				else {
					if (flag) {
						dq.pop_back();
					}
					else {
						dq.pop_front();
					}
				}
			}
		}
		if (flag1) cout << "error" << '\n';
		else {
			if (flag) {
				cout << '['; 
				for (int i = dq.size()-1; i >=0; i--) {
					cout << dq[i];
					if (i == 0) continue;
					cout << ',';
				}
				cout << ']';
			}
			else {
				cout << '[';
				for (int i =0; i < dq.size(); i++) {
					cout << dq[i];
					if (i == dq.size()-1) continue;
					cout << ',';
				}
				cout << ']';
			}
			cout << '\n';
		}

	}
}