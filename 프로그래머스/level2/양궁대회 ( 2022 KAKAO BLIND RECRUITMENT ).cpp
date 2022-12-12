#include<bits/stdc++.h>
using namespace std;
int score[11] = { 10,9,8,7,6,5,4,3,2,1,0 };
vector<int> v;
int t = 0;
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    int flag = -1;
    for (int i = 0; i < (1 << 11); i++) {

        int rsum = 0;
        int asum = 0;
        int arrow = 0;
        v.clear();
        v.resize(11);

        for (int j = 0; j < 11; j++) {
            if (i & (1 << j)) {
                rsum += score[j];
                v[j] = info[j] + 1;
                arrow += (info[j] + 1);

            }
            else {
                v[j] = 0;
                if (info[j]) asum += score[j];
            }
        }
        if (arrow > n) continue;

        if (n > arrow) v[10] += (n - arrow);

        if (rsum - asum > t) {
            t = rsum - asum;
            answer = v;
        }
        else if (rsum - asum == t && t > 0) {
            for (int i = 10; i >= 0; i--) {
                if (v[i] > answer[i]) {
                    t = rsum - asum;
                    answer = v;
                    break;
                }
                else if (v[i] < answer[i]) {
                    break;
                }
            }
        }
    }
    if (t == 0) answer.push_back(-1);


    return answer;
}
