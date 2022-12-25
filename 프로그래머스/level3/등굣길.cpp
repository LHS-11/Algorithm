#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[104][104];
int p[104][104];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    dp[0][0] = 1;

    for (auto puddle : puddles) {
        p[puddle[1] - 1][puddle[0] - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (p[i][j]) continue;
            if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    return dp[n - 1][m - 1];
}
