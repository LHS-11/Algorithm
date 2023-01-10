#include <bits/stdc++.h>
using namespace std;
int vis[104];
vector<pair<int, int>> node[104];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;

    for (auto c : costs)
    {
        node[c[0]].push_back({c[1], c[2]});
        node[c[1]].push_back({c[0], c[2]});
    }

    // 프림 알고리즘
    // 0부터 시작
    vis[0] = 1;
    for (int i = 0; i < node[0].size(); i++)
    {
        pq.push({node[0][i].second, node[0][i].first});
    }

    while (pq.size())
    {
        auto cur = pq.top();
        pq.pop();

        // 연결된 최단거리인 노드
        if (!vis[cur.second])
        {
            vis[cur.second] = 1;
            answer += cur.first;
            for (int i = 0; i < node[cur.second].size(); i++)
            {
                int nxt = node[cur.second][i].first;

                // 그 다음 노드에 연결된 노드들 pq에 넣기
                if (!vis[nxt])
                {
                    pq.push({node[cur.second][i].second, nxt});
                }
            }
        }
    }

    return answer;
}