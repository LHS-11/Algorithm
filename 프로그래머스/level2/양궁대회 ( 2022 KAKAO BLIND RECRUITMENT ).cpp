#include<bits/stdc++.h>
using namespace std;
// 완전탐색? -> 비트마스킹 
// 11111111111
int score[11] = { 10,9,8,7,6,5,4,3,2,1,0 };
vector<int> v;
int t = 0; // 차이 값
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    int mx = 0;
    for (int i = 0; i < 11; i++) {
        if (info[i]) {
            mx += score[i];
        }
    }

    for (int i = 0; i < (1 << 12); i++) {

        int k = n;
        int smx = mx;
        int sum = 0;
        v.clear();
        v.resize(11);

        for (int j = 0; j < 11; j++) {
            if (i & (1 << j)) {
                if (info[j]) {
                    if (k >= info[j] + 1) {
                        sum += score[j];
                        smx -= score[j];
                        k -= info[j] + 1;
                        v[j] = info[j] + 1;
                    }
                }
                else {
                    if (k > 0 && info[j] == 0) {
                        sum += score[j];
                        v[j] = 1;
                        k -= 1;
                    }
                }
            }
        }
        if (k > 0) {
            v[10] += k;
        }
        if (smx < sum && t <= (sum - smx)) {
            t = sum - smx;
            answer = v;

        }
    }
    if (t == 0) {
        answer.push_back(-1);
    }

    return answer;
}