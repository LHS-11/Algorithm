#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
vector<pair<int, int>> node[204];
int d[204], d1[204];
// 다익스트라로 시작점에서 모든점의 최단거리를 구하고 각 점에서 또 다익스트라
// a,b,s로 각각 다익스트라를 돌려서 각 거리 배열을 갱신한 뒤 각 점에서 갱신한 거리 배열의 합의 최소를 구해도 됨
void go(int st, int d[])
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, st});

    while (pq.size())
    {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.second] < cur.first)
            continue;

        for (int i = 0; i < node[cur.second].size(); i++)
        {
            int cost = cur.first + node[cur.second][i].second;
            int nxt = node[cur.second][i].first;
            if (cost < d[nxt])
            {
                d[nxt] = cost;
                pq.push({d[nxt], nxt});
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = INF;

    for (auto f : fares)
    {
        node[f[0]].push_back({f[1], f[2]});
        node[f[1]].push_back({f[0], f[2]});
    }

    fill(d, d + 204, INF);

    d[s] = 0;
    go(s, d);

    answer = min(answer, d[a] + d[b]);

    for (int i = 1; i <= n; i++)
    {
        if (i == s || d[i] == INF)
            continue;
        fill(d1, d1 + 204, INF);
        d1[i] = 0;
        go(i, d1);
        answer = min(answer, d1[a] + d1[b] + d[i]);
    }

    return answer;
}