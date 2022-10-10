// 이 문제는 메모이제이션을 해서 풀되 Top-bottom 방식으로는 풀 수 없음 
#include<bits/stdc++.h>
using namespace std;
int dp[100004];
int go(int k) {
    if (k == 0) return 0;
    else if (k == 1) return 1;

    int& ans = dp[k];
    if (ans != -1) return ans;

    return ans = (go(k - 1) + go(k - 2)) % 1234567;
}
int solution(int n) {
    int answer = 0;
    memset(dp, -1, 100004);
    //answer=go(n)%1234567;

    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    answer = dp[n];
    return answer;
}