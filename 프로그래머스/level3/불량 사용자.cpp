#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
vector<string> ban, user;
vector<string> repo;
int vis[9];
int chk[9];
int answer, flag;
void check(int k, int sz) {

    if (repo.size() == sz) {

        if (flag) return;
        for (int i = 0; i < sz; i++) {
            if (repo[i].size() != ban[i].size()) return;
            for (int j = 0; j < ban[i].size(); j++) {
                if (ban[i][j] == '*') continue;
                if (ban[i][j] != repo[i][j]) {
                    return;
                }
            }
        }
        answer++;
        flag = 1;
        return;
    }


    for (int i = 0; i < sz; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        repo.push_back(ans[i]);
        check(i, sz);
        repo.pop_back();
        chk[i] = 0;

    }
}
void go(int k, int sz) {

    if (ans.size() == sz) {
        flag = 0;
        check(0, sz);
        return;
    }


    for (int i = k; i < user.size(); i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        ans.push_back(user[i]);
        go(i, sz);
        ans.pop_back();
        vis[i] = 0;
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    ban = banned_id;
    user = user_id;
    int sz = ban.size();
    go(0, sz);

    return answer;
}