#include <bits/stdc++.h>
using namespace std;
int dp[100004][4], ans;
int solution(vector<vector<int> > land)
{
    int answer = 0;


    for (int i = 0; i < 4; i++) dp[0][i] = land[0][i];

    for (int i = 1; i < land.size(); i++) {

        dp[i][0] = max({ dp[i - 1][1],dp[i - 1][2],dp[i - 1][3] }) + land[i][0];
        dp[i][1] = max({ dp[i - 1][0],dp[i - 1][2],dp[i - 1][3] }) + land[i][1];
        dp[i][2] = max({ dp[i - 1][1],dp[i - 1][0],dp[i - 1][3] }) + land[i][2];
        dp[i][3] = max({ dp[i - 1][1],dp[i - 1][2],dp[i - 1][0] }) + land[i][3];

    }
    int sz = land.size() - 1;
    answer = max({ dp[sz][0],dp[sz][1],dp[sz][2],dp[sz][3] });

    return answer;
}