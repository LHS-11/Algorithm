#include<bits/stdc++.h>
using namespace std;
int vis[54];
bool check(string a, string b) {
    int sz = a.size();
    int cnt = 0;
    for (int i = 0; i < sz; i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }
    if (cnt >= 2) {
        return false;
    }
    else return true;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;


    queue<pair<string, int>> q;
    q.push({ begin,0 });

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == target) {
            return cur.second;
        }

        for (int i = 0; i < words.size(); i++) {
            if (check(cur.first, words[i]) && !vis[i]) {
                vis[i] = 1;
                q.push({ words[i],cur.second + 1 });
            }
        }
    }
    return answer;
}