#include<bits/stdc++.h>
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int vis[5][5];
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++) {

        vector<string> s = places[i];

        int flag = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s[i].size(); j++) {
                if (s[i][j] == 'P') {
                    flag = 0;
                    queue<tuple<int, int, int>> q;
                    q.push({ i,j,0 });
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        int x, y, cnt;
                        tie(y, x, cnt) = q.front();

                        q.pop();

                        if (s[y][x] == 'P' && !(i == y && j == x)) {
                            flag = 1;
                            break;
                        }

                        for (int i = 0; i < 4; i++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];

                            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

                            if (s[ny][nx] != 'X' && cnt < 2) {
                                q.push({ ny,nx,cnt + 1 });
                            }
                        }
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
            if (flag) break;

        }
        if (!flag) answer.push_back(1);
        else answer.push_back(0);

    }


    return answer;
}