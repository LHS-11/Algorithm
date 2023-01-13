#include <bits/stdc++.h>
using namespace std;
int vis[27][27][4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
// bfs + dp
// 일단 직선으로 가는건 그 전의 방향과 같은 방향일 때만 직선, 좌우는 직각이 됨
// 해당 노드에 도착했을 때 4가지 방향의 dp를 다 구해서 그 4개 중 최소값을 구함
int solution(vector<vector<int>> board)
{
    int answer = INT_MAX;
    int n = board.size();

    fill(&vis[0][0][0], &vis[0][0][0] + 27 * 27 * 4, INT_MAX);

    queue<tuple<int, int, int>> q;

    q.push({0, 0, -1});
    vis[0][0][0] = 0;

    while (q.size())
    {
        int x, y, dir;
        tie(y, x, dir) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            int k;
            if (dir == -1)
            {
                k = 100;
            }
            else
                k = (i == dir ? 100 : 600);

            if (ny < 0 || nx < 0 || nx >= n || ny >= n || board[ny][nx] == 1)
                continue;

            if (vis[ny][nx][i] >= vis[y][x][dir] + k)
            {
                vis[ny][nx][i] = vis[y][x][dir] + k;
                q.push({ny, nx, i});
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        answer = min(answer, vis[n - 1][n - 1][i]);
    }
    return answer;
}