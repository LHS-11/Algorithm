#include<bits/stdc++.h>
using namespace std;
vector<char> v;
map<int, int> mp;
int ans, vis[8];
char flag;
bool check(int k) {

    if (k == 1 || k == 0) return false;

    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) return false;
    }
    return true;
}
void go(int sz, string str) {

    if (v.size() == sz) {

        string s = "";
        for (auto c : v) s += c;

        if (!mp[stoi(s)] && check(stoi(s))) {
            ans++;
            mp[stoi(s)]++;
        }

        return;
    }

    flag = '*';

    for (int i = 0; i < str.size(); i++) {
        if (vis[i] || flag == str[i]) continue;
        vis[i] = 1;
        v.push_back(str[i]);
        go(sz, str);
        flag = str[i];
        v.pop_back();
        vis[i] = 0;
    }


}
int solution(string numbers) {

    for (int i = 1; i <= numbers.size(); i++) {
        go(i, numbers);
        memset(vis, 0, sizeof(vis));
        v.clear();
    }
    return ans;
}