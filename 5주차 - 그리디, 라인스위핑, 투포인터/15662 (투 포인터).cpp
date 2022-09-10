#include<bits/stdc++.h>
using namespace std;
int t;
vector<int> v[1004];
vector<int> v1[1004];
int k;
void rotateL(vector<int>& v) {
	rotate(v.begin(), v.begin() + 1, v.end());
}
void rotateR(vector<int>& v) {
	rotate(v.begin(), v.begin() + v.size() - 1, v.end());
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string s;
		cin >> s;
		for (auto c : s) {
			if (c == '1') v[i].push_back(1);
			else v[i].push_back(0);
		}
	}
	cin >> k;
	for (int i = 1; i <= t; i++) {
		v1[i] = v[i];
	}
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b;
		c = -b;
		int flag = 0;
		for (int i = a; i > 0; i--) {
			if (i!=1 && v[i - 1][2] == v[i][6]) {
				flag = 1;
			}
			if (b == 1) rotateR(v1[i]); //v[3] 시계방향
			else rotateL(v1[i]);
			b = -1*b;
			if (flag) break;
		}
		flag = 0;
		if (a != t && v[a][2] != v[a + 1][6]) {
			for (int i = a+1; i <= t; i++) {
				if (i != t && v[i + 1][6] == v[i][2]) {
					flag = 1;
				}
				if (c == 1) rotateR(v1[i]);
				else rotateL(v1[i]);
				c = -1*c;
				if (flag) break;
			}
		}
		for (int i = 1; i <= t; i++) {
			v[i] = v1[i];
		}
	}
	int ans = 0;
	for (int i = 1; i <= t; i++) {
		if (v[i][0] == 1) ans++;
	}
	cout << ans;
}