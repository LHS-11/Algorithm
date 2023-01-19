#include <bits/stdc++.h>
using namespace std;
// 7 10 14 20 21 28 30
bool check(long long k, int n, vector<int> &times)
{
    long long sum = 0;
    for (auto t : times)
    {
        sum += k / t;
    }
    if (sum >= (long long)n)
        return true;
    return false;
}
long long solution(int n, vector<int> times)
{
    long long answer = 0;

    long long l = 0, r = 1e13;

    while (l <= r)
    {
        long long m = (l + r) >> 1;

        if (check(m, n, times))
        {
            r = m - 1;
            answer = m;
        }
        else
            l = m + 1;
    }

    return answer;
}