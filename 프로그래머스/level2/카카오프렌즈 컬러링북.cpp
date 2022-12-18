#include<bits/stdc++.h>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    int vis[104][104];
    int cnt = 0;

    memset(vis, 0, sizeof(vis));



    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << picture[i][j];
            if (picture[i][j] && !vis[i][j]) {
                queue<pair<int, int>> q;
                int x = picture[i][j];
                number_of_area++;

                q.push({ i,j });
                vis[i][j] = 1;
                cnt = 1;

                while (q.size()) {
                    auto cur = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int nx = cur.second + dx[i];
                        int ny = cur.first + dy[i];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                        if (!vis[ny][nx] && x == picture[ny][nx]) {
                            vis[ny][nx] = 1;
                            cnt++;
                            q.push({ ny,nx });
                        }
                    }
                }
                max_size_of_one_area = max(max_size_of_one_area, cnt);
            }
        }
        cout << endl;
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}
