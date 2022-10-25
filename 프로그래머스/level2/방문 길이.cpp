#include<bits/stdc++.h>
using namespace std;
int vis[11][11][11][11];
int solution(string dirs) {
    int answer = 0;

    int y = 5, x = 5; // 시작

    for (auto c : dirs) {

        if (c == 'U') {
            if (y - 1 < 0) continue;
            if (!vis[y][x][y - 1][x]) {
                answer++;
                vis[y][x][y - 1][x] = 1;
                vis[y - 1][x][y][x] = 1;
            }
            y = y - 1;


        }
        else if (c == 'D') {
            if (y + 1 > 10) continue;
            if (!vis[y][x][y + 1][x]) {
                answer++;
                vis[y][x][y + 1][x] = 1;
                vis[y + 1][x][y][x] = 1;
            }
            y = y + 1;

        }
        else if (c == 'R') {
            if (x + 1 > 10) continue;
            if (!vis[y][x][y][x + 1]) {
                answer++;
                vis[y][x][y][x + 1] = 1;
                vis[y][x + 1][y][x] = 1;
            }
            x = x + 1;

        }
        else {
            if (x - 1 < 0) continue;
            if (!vis[y][x][y][x - 1]) {
                answer++;
                vis[y][x][y][x - 1] = 1;
                vis[y][x - 1][y][x] = 1;
            }
            x = x - 1;

        }


    }

    return answer;
}