#include<bits/stdc++.h>
using namespace std;
set<vector<string>> st;
vector<string> user, ban;
vector<string> a;
int vis[9], answer;
bool check(vector<string> a) {
    for (int i = 0; i < ban.size(); i++) {
        if (ban[i].size() != a[i].size()) return false;
        for (int j = 0; j < ban[i].size(); j++) {
            if (ban[i][j] == '*') continue;
            if (ban[i][j] != a[i][j]) return false;
        }
    }
    return true;
}
void go() {

    if (a.size() == ban.size()) {

        if (check(a)) {
            vector<string> tmp = a;
            sort(tmp.begin(), tmp.end());
            if (st.find(tmp) == st.end()) {
                st.insert(tmp);
                answer++;
            }
        }
        return;
    }

    for (int i = 0; i < user.size(); i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        a.push_back(user[i]);
        go();
        a.pop_back();
        vis[i] = 0;
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    user = user_id;
    ban = banned_id;

    go();
    return answer;
}