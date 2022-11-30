#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> r;
int vis[10];
vector<int> key;
string chk[1000];
int answer, idx1; // 초기화 X 
void go(int idx, int k, int sz) {

    if (k == sz) { // 2. 유일성 만족하는지 확인

        map<string, int> mp;
        int flag = 0;
        for (int i = 0; i < r.size(); i++) {
            string s = "";
            for (int j = 0; j < key.size(); j++) {
                s += r[i][key[j]];
            }
            if (!mp[s]) {
                mp[s]++;
            }
            else {
                flag = 1;
                break;
            }
        }
        if (!flag) { // 3. 최소성 만족하는지 확인
            int flag1 = 0;
            string s = "";
            for (auto e : key) {
                s += to_string(e);
            }
            for (int i = 0; i < idx1; i++) { // 포함이 되는지 안되는지 체크
                for (int j = 0; j < chk[i].size(); j++) { // 02
                    flag1 = 0;
                    for (int k = 0; k < s.size(); k++) { // 012
                        if (chk[i][j] == s[k]) {
                            flag1 = 1;
                        }
                    }
                    if (!flag1) break;
                }
                if (flag1) break;
            }
            if (!flag1) {
                chk[idx1] = s;
                idx1++;
                answer++;
            }
        }

        return;
    }


    for (int i = idx; i < r[0].size(); i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        key.push_back(i);
        go(i, k + 1, sz);
        key.pop_back();
        vis[i] = 0;
    }

}
int solution(vector<vector<string>> relation) {

    r = relation;

    // 1. 만들 수 있는 조합을 다 구하기
    // 2. 유일성 만족하는지 확인
    // 3. 최소성 만족하는지 확인


    for (int i = 0; i <= r[0].size(); i++) {
        go(0, 0, i);
        memset(vis, 0, sizeof(vis));
        key.clear();
    }

    return answer;
}