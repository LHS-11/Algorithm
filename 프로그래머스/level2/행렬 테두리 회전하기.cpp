#include<bits/stdc++.h>
using namespace std;
int mapp[101][101];
int check(int r, int c, int nr, int nc) { // 행, 렬 

    int ans = mapp[r][c];
    // r행, c~nc열
    for (int i = c; i <= nc; i++) ans = min(ans, mapp[r][i]);
    // r~nr행 , nc열
    for (int i = r; i <= nr; i++) ans = min(ans, mapp[i][nc]);

    // nr행, nc~c열
    for (int i = c; i <= nc; i++) ans = min(ans, mapp[nr][i]);
    // nr~r행, c열
    for (int i = r; i <= nr; i++) ans = min(ans, mapp[i][c]);

    return ans;
}
void rotate(int r, int c, int nr, int nc) {
    vector<int> v;
    // r행, c~nc열
    for (int i = c; i <= nc; i++) v.push_back(mapp[r][i]);
    // r~nr행 , nc열
    for (int i = r + 1; i <= nr; i++) v.push_back(mapp[i][nc]);
    // nr행, nc~c열
    for (int i = nc - 1; i >= c; i--) v.push_back(mapp[nr][i]);
    // nr~r행, c열
    for (int i = nr - 1; i > r; i--) v.push_back(mapp[i][c]);

    rotate(v.begin(), v.begin() + v.size() - 1, v.end());
    int idx = 0;
    for (int i = c; i <= nc; i++) {
        mapp[r][i] = v[idx];
        idx++;
    }
    // r~nr행 , nc열
    for (int i = r + 1; i <= nr; i++) {
        mapp[i][nc] = v[idx];
        idx++;
    }
    // nr행, nc~c열
    for (int i = nc - 1; i >= c; i--) {
        mapp[nr][i] = v[idx];
        idx++;
    }
    // nr~r행, c열
    for (int i = nr - 1; i > r; i--) {
        mapp[i][c] = v[idx];
        idx++;
    }

}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int cnt = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            mapp[i][j] = cnt;
            cnt++;
        }
    }

    for (auto querie : queries) {
        int r = querie[0];
        int c = querie[1];
        int nr = querie[2];
        int nc = querie[3];
        rotate(r, c, nr, nc);
        answer.push_back(check(r, c, nr, nc));
    }

    return answer;
}