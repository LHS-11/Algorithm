﻿#include<bits/stdc++.h>
using namespace std;
int dp[60004];
int solution(int n) {
    int answer = 0;

    dp[1] = 1;
    dp[0] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    answer = dp[n];

    return answer;
}