#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
int n, vis[21], a[21];
vector<int> v[21];
int cnt[21];
int ans = INF;
void dfs(int now, int t) {
	vis[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int nxt = v[now][i];
		if (vis[nxt] || a[nxt] != t) continue;
		vis[nxt] = t;
		dfs(nxt, t);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> cnt[i];

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		while (x--) {
			int y; cin >> y;
			v[i].push_back(y);
		}
	}
	for (int i = 1; i < (1 << n) - 1; i++) {
		int idx1 = -1, idx2 = -1;
		int sum1 = 0, sum2 = 0;
		memset(vis, 0, sizeof(vis));
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				a[j + 1] = 1;
				sum1 += cnt[j + 1];
				idx1 = j + 1;
			}
			else {
				a[j + 1] = 2;
				sum2 += cnt[j + 1];
				idx2 = j + 1;
			}
		}
		dfs(idx1, 1);
		dfs(idx2, 2);
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				flag = 1;
				break;
			}
		}
		if (!flag) ans = min(ans, abs(sum1 - sum2));
	}
	ans == INF ? cout << -1 : cout << ans;
}