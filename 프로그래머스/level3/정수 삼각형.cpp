#include<bits/stdc++.h>
using namespace std;
int dp[504][10000];// dp[층수][몇번째]
int solution(vector<vector<int>> triangle) {

    int sz = triangle.size() - 1;

    for (int i = 0; i < triangle[sz].size(); i++) {
        dp[sz][i] = triangle[sz][i];
    }

    for (int i = triangle.size() - 2; i >= 0; i--) { // 3~ 0
        for (int j = 0; j < triangle[i].size(); j++) { // 4
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }

    return dp[0][0];
}