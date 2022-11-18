#include<bits/stdc++.h>
using namespace std;
// 연속해서 같은 발음을 하는 것  X
// 네 가지 발음을 조합과 그 조합으로 만든 단어가 아닌 것은 못만듦
int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> v = { "aya","ye","woo","ma" };


    for (auto s1 : babbling) {
        map<string, int> mp;
        for (auto s : v) mp[s] = -1;

        string s = s1;
        for (int i = 0; i < v.size(); i++) {
            int flag;
            while (1) {
                flag = 0;
                auto iter = s.find(v[i]);
                if (iter != string::npos) {
                    if (iter == mp[v[i]]) {
                        break;
                    }
                    flag = 2;
                    s.erase(iter, v[i].size());
                    for (int j = 0; j < v[i].size(); j++) s.insert(iter, "x");

                    mp[v[i]] = iter + v[i].size();
                }
                if (!flag) break;
            }
        }
        s.erase(unique(s.begin(), s.end()), s.end());
        if (s.size() == 1 && s[0] == 'x') answer++;
    }

    return answer;
}