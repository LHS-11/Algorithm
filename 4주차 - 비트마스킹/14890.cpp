#include<bits/stdc++.h>
using namespace std;
int n, l,ans;
int a[101][101];
int b[101][101];
int go(int a[101][101]) {
	int rst = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		int flag = 0;
		for (int j = 0; j < n-1; j++) {
			if (a[i][j] == a[i][j + 1]) cnt++;
			else if (a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;
			else if (a[i][j] - 1 == a[i][j + 1] && cnt>=0) cnt = -l + 1;
			else {
				flag = 1;
				break;
			}
		}
		if (!flag && cnt>=0) rst++;
	}
	return rst;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[j][i];
		}
	}
	ans = go(a)+go(b);
	cout << ans;
}