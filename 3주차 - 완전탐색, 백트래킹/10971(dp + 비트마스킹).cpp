#include <bits/stdc++.h>
using namespace std;
const int MX = 14;
const int INF = 1e9;
int dis[MX][MX], n, ans = INF;
int dp[MX][1 << MX];
int dfs(int now, int des, int state) {
    if (state == (1 << n) - 1) {
        return dis[now][des] ? dis[now][des] : INF;
    }

    int &ret = dp[now][state];
    if (ret != -1) return ret;

    ret = INF;
    for (int i = 0; i < n; i++) {
        if (now == i || state & (1 << i) || !dis[now][i]) continue;
        ret = min(ret, dfs(i, des, state | (1 << i)) + dis[now][i]);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dis[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        memset(dp, -1, sizeof(dp));
        ans = min(ans, dfs(i, i, 1 << i));
    }

    cout << ans;
}
