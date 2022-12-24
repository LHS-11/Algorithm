#include<bits/stdc++.h>
using namespace std;
int vis[204];
vector<int> v[204];
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (computers[i][j]) {
                v[i].push_back(j);
            }
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            q.push(i);
            vis[i] = 1;
            answer++;

            while (q.size()) {
                auto cur = q.front();
                q.pop();

                for (int i = 0; i < v[cur].size(); i++) {
                    int nxt = v[cur][i];

                    if (!vis[nxt]) {
                        vis[nxt] = 1;
                        q.push(nxt);
                    }

                }
            }
        }
    }


    return answer;
}
