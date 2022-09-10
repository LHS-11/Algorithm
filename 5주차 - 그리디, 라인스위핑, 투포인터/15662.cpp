#include<bits/stdc++.h>
using namespace std;
int t;
vector<int> v[1004];
int k;
void rotateL(vector<int>& v) {
	rotate(v.begin(), v.begin() + 1, v.end());
}
void rotateR(vector<int>& v) {
	rotate(v.begin(), v.begin() + v.size() - 1, v.end());
}
void goLeft(int a, int b) {
	if (b == 1) { // 시계 방향
		if (a - 1 > 0 && v[a - 1][2] != v[a][6]) {
			goLeft(a - 1, -b);
		}
		rotateR(v[a]);
	}
	else if (b == -1) { // 반시계 방향

		if (a - 1 > 0 && v[a - 1][2] != v[a][6]) {
			goLeft(a - 1, -b);
		}
		rotateL(v[a]);
	}
}
void goRight(int a, int b) {
	if (b == 1) {
		if (a + 1 <= t && v[a][2] != v[a + 1][6]) {
			goRight(a + 1, -b);
		}
		rotateR(v[a]);
	}
	else if (b == -1) {
		if (a + 1 <= t && v[a][2] != v[a + 1][6]) {
			goRight(a + 1, -b);
		}
		rotateL(v[a]);
	}
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
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;

		goLeft(a, b);
		if (b == 1) rotateL(v[a]);
		else rotateR(v[a]);
		goRight(a, b);
	}
	int ans = 0;
	for (int i = 1; i <= t; i++) {
		if (v[i][0] == 1) ans++;
	}
	cout << ans;
}