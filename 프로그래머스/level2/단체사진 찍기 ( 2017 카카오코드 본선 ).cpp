#include<bits/stdc++.h>
using namespace std;
string s = "";
int answer;
int vis[8];
char c[8] = { 'A','C','F','J','M','N','R','T' };
void go(int k, int idx, vector<string> data) {
    if (k == 8) {

        for (auto d : data) {
            int num = s.find(s[0]) - s.find(s[2]);
            if (d[1] == '=') {

                if (abs(num) != (d[4] - '0')) return;

            }
            else if (d[2] == '>') {
                if (abs(num) <= (d[4] - '0')) return;

            }
            else {
                if (abs(num) >= (d[4] - '0')) return;

            }
        }

        answer++;

        return;
    }

    for (int i = 0; i < 8; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        s += c[i];
        go(k + 1, i, data);
        s.pop_back();
        vis[i] = 0;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    go(0, 0, data);
    return answer;
}