#include<bits/stdc++.h>
using namespace std;
// 왼쪽 발의 위치와 오른쪽 발의 위치
int dp[100004][5][5];
int a[100004], idx;
int dir(int a, int b) {
	if (a == 0) {
		return 2;
	}
	else if (a == b) {
		return 1;
	}
	else if (abs(a - b) == 1) {
		return 3;
	}
	else  return 4;
}
int go(int k, int x, int y) { // top-bottom 방식

	if (k == idx-1) return 0;

	int& ans = dp[k][x][y];
	if (ans != -1) return ans;

	int l = go(k + 1, a[k], y) + dir(x, a[k]);
	int r = go(k + 1, x, a[k]) + dir(y, a[k]);
	return ans = min(l, r);

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	a[idx] = n;
	idx++;
	while (n) {
		cin >> n;
		a[idx++] = n;
		
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0, 0);
}
