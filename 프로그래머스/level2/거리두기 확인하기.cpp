#include<bits/stdc++.h>
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dx1[8] = { -2,0,2,0,-1,-1,1,1 };
int dy1[8] = { 0,-2,0,2,-1,1,-1,1 };
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++) {

        vector<string> s = places[i];

        int flag = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s[i].size(); j++) {

                queue<pair<int, int>> q;

                if (s[i][j] == 'P') {
                    q.push({ i,j });
                }

                while (!q.empty()) {

                    auto cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = cur.second + dx[i];
                        int ny = cur.first + dy[i];

                        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                        if (s[ny][nx] == 'P') {
                            flag = 1;
                            break;
                        }

                    }
                    if (flag) break;
                    else {
                        queue<tuple<int, int, int>> q1;
                        q1.push({ cur.first,cur.second,0 });

                        while (q1.empty()) {
                            int x, y, cnt;
                            tie(y, x, cnt) = q1.front();
                            q1.pop();

                            if (s[y][x] == 'P') {
                                flag = 1;
                                break;
                            }
                            for (int i = 0; i < 8; i++) {
                                int nx = cur.second + dx1[i];
                                int ny = cur.first + dy1[i];
                                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                                if (s[ny][nx] == 'O' && cnt < 2) {
                                    q1.push({ ny,nx,cnt + 1 });
                                }

                            }
                        }
                    }
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