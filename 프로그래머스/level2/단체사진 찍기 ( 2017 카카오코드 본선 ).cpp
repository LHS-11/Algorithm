#include<bits/stdc++.h>
using namespace std;
int answer;
int ans = 0;
void go(string s, vector<string> data, int vis[], char c[]) {
    if (s.size() == 8) {
        for (auto d : data) {
            int num = s.find(d[0]) - s.find(d[2]);

            if (d[3] == '=') {
                if (abs(num) - 1 != (d[4] - '0')) return;

            }
            else if (d[3] == '>') {
                if (abs(num) - 1 <= (d[4] - '0')) return;

            }
            else if (d[3] == '<') {
                if (abs(num) - 1 >= (d[4] - '0')) return;

            }
        }

        answer++;

        return;
    }


    for (int i = 0; i < 8; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        s += c[i];
        go(s, data, vis, c);
        s.pop_back();
        vis[i] = 0;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    int vis[8];
    memset(vis, 0, sizeof(vis));
    char c[8] = { 'A','C','F','J','M','N','R','T' };

    go("", data, vis, c);
    return answer;
}