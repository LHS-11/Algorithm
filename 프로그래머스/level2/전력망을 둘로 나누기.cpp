#include<bits/stdc++.h>
using namespace std;
int vis[104];
vector<int> edge[104];
int go(int node, int a, int b) {

    queue<int> q;
    q.push(node);

    int cnt = 1;
    vis[node] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < edge[cur].size(); i++) {
            int nxt = edge[cur][i];
            if (vis[nxt]) continue;
            if (!(a == cur && b == nxt || b == cur && a == nxt)) {
                vis[nxt] = 1;
                q.push(nxt);
                cnt++;
            }
        }
    }
    return cnt;

}
int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;

    for (int i = 0; i < wires.size(); i++) {

        edge[wires[i][0]].push_back(wires[i][1]);
        edge[wires[i][1]].push_back(wires[i][0]);
    }


    for (int i = 0; i < wires.size(); i++) {
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= n; j++) {
            int ans = go(j, wires[i][0], wires[i][1]);
            int ans1 = n - ans;
            answer = min(answer, abs(ans - ans1));
        }
    }

    return answer;
}