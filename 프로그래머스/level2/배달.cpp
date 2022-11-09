#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
int dis[51], vis[51];
vector<pair<int, int>> v[51];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (auto r : road) {
        v[r[0]].push_back({ r[1],r[2] });
        v[r[1]].push_back({ r[0],r[2] });
    }

    fill(dis, dis + 51, INF);
    dis[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int nxt = v[cur][i].first;
            int t = v[cur][i].second;

            if (dis[cur] + t < dis[nxt]) {
                q.push(nxt);
                dis[nxt] = dis[cur] + t;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dis[i] <= K) answer++;
    }



    return answer;
}