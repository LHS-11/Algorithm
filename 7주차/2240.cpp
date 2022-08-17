#include<bits/stdc++.h>
using namespace std;
int t, w;
int a[1004];
int dp[1004][3][31];
int go(int idx, int wood, int cnt) {

	if (idx == t) return 0; //기저 사례

	int& ans = dp[idx][wood][cnt]; //메모이제이션

	if (ans != -1) return ans; // 두번이상 계산하지 않기 위해서 메모이제이션으로 저장한 값이 있다면 바로 호출

	if (a[idx] == wood) { // 로직
		if (cnt < w) return ans = max(go(idx + 1, wood, cnt) + 1, go(idx + 1, 3 - wood, cnt + 1));
		else return ans = go(idx + 1, wood, cnt) + 1;
	}
	else {
		if (cnt < w) return ans = max(go(idx + 1, wood, cnt), go(idx + 1, 3 - wood, cnt + 1) + 1);
		else return ans = go(idx + 1, wood, cnt);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t >> w;
	for (int i = 0; i < t; i++) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	cout << go(0, 1, 0);
}