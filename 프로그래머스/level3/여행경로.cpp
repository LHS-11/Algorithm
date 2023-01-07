#include <bits/stdc++.h>
using namespace std;
multimap<string, string> mtp; // 경로 표시
map<string, int> mp;          // 경로 숫자로 변환
int vis[10004][10004];
vector<string> answer;
vector<string> ans;
void dfs(string cur, int sz)
{

    if (answer.size() == sz)
    {
        if (!ans.size())
            ans = answer;
        return;
    }

    for (auto it = mtp.lower_bound(cur); it != mtp.upper_bound(cur); it++)
    {
        string nxt = it->second;

        if (!vis[mp[cur]][mp[nxt]])
            continue;
        answer.push_back(nxt);
        vis[mp[cur]][mp[nxt]]--;
        dfs(nxt, sz);
        vis[mp[cur]][mp[nxt]]++;
        answer.pop_back();
    }
}
vector<string> solution(vector<vector<string>> tickets)
{

    sort(tickets.begin(), tickets.end());

    int idx = 0;
    for (auto t : tickets)
    {
        if (mp.find(t[0]) == mp.end())
        {
            mp[t[0]] = idx++;
        }
        if (mp.find(t[1]) == mp.end())
        {
            mp[t[1]] = idx++;
        }
        mtp.insert({t[0], t[1]});
        vis[mp[t[0]]][mp[t[1]]]++;
    }

    answer.push_back("ICN");
    dfs("ICN", tickets.size() + 1);

    return ans;
}