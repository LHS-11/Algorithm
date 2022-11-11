#include<bits/stdc++.h>
using namespace std;
long long dp[21];
vector<int> solution(int n, long long k) {
    vector<int> answer;


    fill(dp, dp + 21, 1);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] * i;
    }

    vector<int> num;
    for (int i = 1; i <= n; i++) num.push_back(i);

    int cnt = 1;
    while (cnt <= n) {
        long long idx = (k - 1) / dp[n - cnt];
        answer.push_back(num[idx]);
        num.erase(num.begin() + idx);
        k %= dp[n - cnt];
        if (!k) k = dp[n - cnt];
        cnt++;

    }

    return answer;
}