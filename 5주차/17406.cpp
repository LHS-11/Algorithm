#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int tmp,tmp1;
int a[51][51];
int mp[51][51];
int mp1[51][51];
int vis[7];
int ans = 987654321;
vector<tuple<int, int, int>> v;
vector<int> v1;
void go(int r, int c, int s,int mp[51][51],int a[51][51]) { // 효율적으로 이동하는 방법을 알아야함..
	if (s == 0) return;
	for (int i = c - s; i < c + s; i++) {
		mp[r - s][i + 1] = a[r - s][i];
	}
	for (int i = r - s; i < r + s; i++) {
		mp[i + 1][c + s] = a[i][c + s];
	}
	for (int i = c + s; i > c - s; i--) {
		mp[r + s][i - 1] = a[r + s][i];
	}
	for (int i = r + s; i > r - s; i--) {
		mp[i - 1][c - s] = a[i][c - s];
	}
	go(r, c, s - 1,mp,a);
}
void copyMap(int mp[51][51],int a[51][51]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mp[i][j] = a[i][j];
		}
	}
}
void dfs(int sz) {
	if (sz == k) {
		copyMap(mp, a);
		copyMap(mp1, a);
		for (auto t : v1) {
			int r, c, s;
			tie(r, c, s) = v[t];
			go(r, c, s,mp1,mp);
			copyMap(mp, mp1);
		}
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++) {
				sum += mp[i][j];
			}
			ans = min(ans, sum);
		}
		return;
	}
	for (int i = 0; i < k; i++) {
		if (vis[i]) continue;
		v1.push_back(i);
		vis[i] = 1;
		dfs(sz + 1);
		v1.pop_back();
		vis[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	dfs(0);
	cout << ans;
}