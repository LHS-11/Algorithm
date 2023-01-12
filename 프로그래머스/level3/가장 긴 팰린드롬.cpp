#include <bits/stdc++.h>
using namespace std;
int dp[2504][2504];
int solution(string s)
{
    int answer = 1;

    for (int i = 0; i < s.size(); i++)
    {
        dp[i][i] = 1;
    }

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
        }
    }

    for (int i = 2; i < s.size(); i++)
    {
        for (int j = 0; j + i < s.size(); j++)
        {
            if (s[j] == s[j + i] && dp[j + 1][j + i - 1])
            {
                answer = max(i + 1, answer);
                dp[j][j + i] = 1;
            }
        }
    }

    return answer;
}