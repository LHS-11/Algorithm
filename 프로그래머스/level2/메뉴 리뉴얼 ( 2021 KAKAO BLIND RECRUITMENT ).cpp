#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
vector<string> v;
vector<tuple<int, int, string>> ans;
int vis[11];
map<int, int> sz;
void go(int idx, int sz, string s, string s1) {

    if (s1.size() == sz) {
        mp[s1]++;
        v.push_back(s1);
        return;
    }


    for (int i = idx; i < s.size(); i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        s1 += s[i];
        go(i, sz, s, s1);
        s1.pop_back();
        vis[i] = 0;
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (auto str : orders) {
        for (auto i : course) {
            sort(str.begin(), str.end());
            go(0, i, str, "");
            memset(vis, 0, sizeof(vis));
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto c : v) {
        if (mp[c] >= 2) ans.push_back({ c.size(),mp[c],c });
    }


    sort(ans.begin(), ans.end());

    for (auto k : ans) {
        int a, b;
        string c;
        tie(a, b, c) = k;
        if (sz[a] < b) sz[a] = b;
    }

    for (auto k : ans) {
        int a, b;
        string c;
        tie(a, b, c) = k;
        if (sz[a] == b) {
            answer.push_back(c);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}