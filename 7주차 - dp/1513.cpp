#include<bits/stdc++.h>
using namespace std;
#define mod 1000007
int n, m, c;
int a[54][54], dp[54][54][54][54];
int go(int x,int y ,int cnt,int k,int prev) {
	if (x >= m || y >= n) return 0;

	if (x == m - 1 && y == n - 1) {
		if (prev < a[y][x] && cnt==k-1) return 1; // 도착지에 오락실이 있을 떄 
		if (a[y][x] == 0 && cnt == k) return 1; // 도착지에 오락실이 없을 때
		return 0;
	}
	int& ans = dp[y][x][cnt][prev];
	if (ans != -1) return ans;
	else ans = 0;
	
	if (a[y][x]>prev) { // 현재 좌표에서 오락실 체킹을 하고 옆밑으로 진행
		ans += (go(x, y + 1, cnt + 1, k, a[y][x])+go(x + 1, y, cnt + 1, k, a[y][x]))%mod;
	}
	else if (a[y][x] == 0) { 
		ans += (go(x, y + 1, cnt, k, prev) + go(x + 1, y, cnt, k, prev))%mod;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> c; // 세로, 가로
	for (int i = 0; i < c; i++) {
		int x, y;
		cin >> y >> x;
		a[y-1][x-1] = i+1;
	}

	for (int i = 0; i <= c; i++) {
		memset(dp, -1, sizeof(dp));
		cout << go(0, 0, 0, i,0) << ' ';
	}
}