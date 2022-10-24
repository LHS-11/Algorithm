#include<bits/stdc++.h>
using namespace std;
int vis[104][104];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int solution(vector<vector<int> > maps)
{
    int answer = -1;

    queue<pair<int, int>> q;
    q.push({ 0,0 });
    // vis[0][0]=1;

    int ddx = maps[0].size();
    int ddy = maps.size();

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == ddy - 1 && cur.second == ddx - 1) {
            answer = vis[ddy - 1][ddx - 1] + 1;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];

            if (vis[ny][nx] || !maps[ny][nx] || nx < 0 || ny < 0 || nx >= ddx || ny >= ddy) continue;
            vis[ny][nx] = vis[cur.first][cur.second] + 1;
            q.push({ ny,nx });
        }

    }

    return answer;
}