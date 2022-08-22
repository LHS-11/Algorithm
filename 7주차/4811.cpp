#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll dp[34][34];
ll go(int a,int b) {
	if (a == 0 && b == 0) return 1; // 기저 사례

	ll &ans = dp[a][b];  // 메모이제이션 
	if (ans) return ans; 

	if (a > 0) ans += go(a - 1, b + 1); // 온전한 알약을 반으로 쪼개 먹을 때
	if (b > 0) ans += go(a, b - 1); // 반으로 쪼개진 알약을 먹을 때
	return ans;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t) {
		cout << go(t,0) << '\n';
		cin >> t;
	}
}