#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> s; // 중복이 없는 값
map<ll, ll> cnt;
vector<ll> v[300004];
long long solution(vector<int> weights)
{
    long long answer = 0;

    for (int i = 0; i < weights.size(); i++)
    {
        s.insert(weights[i]);
        cnt[weights[i]]++;
    }

    for (auto it = s.begin(); it != s.end(); it++)
    {
        auto w = *it;
        answer += cnt[w] * (cnt[w] - 1) / 2; // 중복된 값 계산

        for (auto x : {2, 3, 4})
        {
            ll sum = 0;
            for (int i = 0; i < v[w * x].size(); i++)
            {
                sum += cnt[v[w * x][i]]; // 해당 w*x의 무게가 나올 수 있는 경우의 수의 모든 합
            }
            answer += (sum * cnt[w]); // 합 * w무게가 나올 수 있는 경우의 수
        }

        for (auto x : {2, 3, 4})
        {
            v[w * x].push_back(w);
        }
    }
    return answer;
}