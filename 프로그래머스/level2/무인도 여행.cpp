#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int vis[104][104];
vector<int> solution(vector<string> maps)
{
    vector<int> answer;

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (vis[i][j] || maps[i][j] == 'X')
                continue;
            queue<pair<int, int>> q;
            int sum = maps[i][j] - '0';
            vis[i][j] = 1;
            q.push({i, j});

            while (q.size())
            {
                auto cur = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = cur.second + dx[i];
                    int ny = cur.first + dy[i];

                    if (nx < 0 || ny < 0 || nx >= maps[i].size() || ny >= maps.size())
                        continue;

                    if (maps[ny][nx] != 'X' && !vis[ny][nx])
                    {
                        vis[ny][nx] = 1;
                        sum += maps[ny][nx] - '0';
                        q.push({ny, nx});
                    }
                }
            }

            if (sum)
                answer.push_back(sum);
        }
    }

    if (answer.size())
    {
        sort(answer.begin(), answer.end());
    }
    else
        answer.push_back(-1);

    return answer;
}