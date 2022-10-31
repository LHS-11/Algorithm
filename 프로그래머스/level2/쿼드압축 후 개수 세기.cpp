#include<bits/stdc++.h>
using namespace std;
int oneCnt, zeroCnt;
void go(int x, int y, int k, vector<vector<int>>& arr) {


    int t = arr[y][x];
    for (int i = y; i < y + k; i++) {
        for (int j = x; j < x + k; j++) {
            if (arr[i][j] != t) {
                go(x, y, k / 2, arr);
                go(x + k / 2, y, k / 2, arr);
                go(x, y + k / 2, k / 2, arr);
                go(x + k / 2, y + k / 2, k / 2, arr);
                return;
            }
        }
    }

    if (t) oneCnt++;
    else zeroCnt++;
    return;

}
vector<int> solution(vector<vector<int>> arr) {

    go(0, 0, arr.size(), arr);

    vector<int> answer = { zeroCnt,oneCnt };

    return answer;
}