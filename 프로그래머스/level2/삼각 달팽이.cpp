#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
    int mx = n * (n + 1) / 2;
    int num = 1;
    int range = n;
    int x = 0, y = -1;

    while (num <= mx) {

        for (int i = y + 1; i <= y + range; i++) {
            map[i][x] = num++;
        }
        y += range;
        range--;
        if (num > mx) break;

        for (int i = x + 1; i <= x + range; i++) {
            map[y][i] = num++;
        }
        x += range;
        range--;
        if (num > mx) break;


        for (int i = 1; i <= range; i++) {
            map[y - i][x - i] = num++;
        }
        x -= range;
        y -= range;
        range--;

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(map[i][j]);
        }
    }

    return answer;
}

