#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
map<string, int> vis;
int solution(vector<vector<string>> clothes) {

    for (int i = 0; i < clothes.size(); i++) {
        mp[clothes[i][1]]++;
    }

    int sum = 1;
    for (auto c : clothes) {
        if (!vis[c[1]]) {
            vis[c[1]] = 1;
            sum *= (mp[c[1]] + 1);
        }
    }

    return sum - 1;
}