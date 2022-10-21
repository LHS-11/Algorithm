#include<bits/stdc++.h>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    int cnt = 0;
    for (auto s : skill_trees) {
        int flag = 0;
        int vis[27];
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < s.size(); i++) {

            for (int j = 0; j < skill.size(); j++) {
                if (s[i] == skill[j]) {
                    for (int k = 0; k < j; k++) {
                        if (!vis[skill[k] - 'A']) {
                            flag = 1; break;
                        }
                    }
                    if (flag) break;
                    vis[skill[j] - 'A']++;
                }
            }
            if (flag) break;
        }
        if (!flag) answer++;

    }

    return answer;
}