#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
map<int, int> money;
vector<int> node[10004];
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{

    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++)
    {
        mp[enroll[i]] = i;
    }

    for (int i = 0; i < referral.size(); i++)
    {
        if (referral[i] == "-")
        {
            node[mp[enroll[i]]].push_back(-1);
        }
        else
            node[mp[enroll[i]]].push_back(mp[referral[i]]);
    }

    for (int i = 0; i < seller.size(); i++)
    {
        int now = mp[seller[i]];

        queue<pair<int, int>> q;
        q.push({now, amount[i] * 100});

        while (q.size())
        {
            auto now = q.front();
            q.pop();

            if (now.first == -1)
                break;
            int profit = now.second * 0.1;
            int m = now.second - profit;
            money[now.first] += m;

            for (int i = 0; i < node[now.first].size(); i++)
            {
                int nxt = node[now.first][i];
                // 분배금이 없는데 굳이 넣을 필요가 없음
                if (profit)
                    q.push({nxt, now.second * 0.1});
            }
        }
    }

    for (int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(money[i]);
    }

    return answer;
}