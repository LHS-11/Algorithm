#include<bits/stdc++.h>
using namespace std;
int score[11] = { 10,9,8,7,6,5,4,3,2,1,0 };
vector<int> v; // 화살의 갯수 담는 곳
int t = -1; // 차이 값
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    int mx = 0;
    for (int i = 0; i < 11; i++) {
        if (info[i]) {
            mx += score[i];
        }
    }

    for (int i = 0; i < (1 << 11); i++) {

        int cnt = n; // 쏠 수 있는 화살의 갯수
        int asum = mx; // 어피치의 최대 점수
        int rsum = 0; // 라이언의 점수
        v.clear();
        v.resize(11);
        int flag = -1;

        for (int j = 0; j < 11; j++) {
            if (i & (1 << j)) { // 라이언이 어피치를 이기는 경우
                flag = j;
                if (info[j]) { // 라이언이 해당 score[j] 의 점수에 1개 이상 화살을 맞췄을 때
                    if (cnt >= info[j] + 1) { // 남아 있는 화살의 수로 라이언을 이길 수 있을 때
                        rsum += score[j];
                        asum -= score[j];
                        cnt -= info[j] + 1;
                        v[j] = info[j] + 1;
                    }
                }
                else { // 라이언이 해당 score[j] 의 점수에 0개의 화살을 맞췄을 때
                    if (cnt > 0 && info[j] == 0) { // 남아 있는 화살에서 1개의 화살을 맞춰 라이언을 이길 때 
                        rsum += score[j];
                        v[j] = 1;
                        cnt -= 1;
                    }
                }

            }
        }
        if (flag > 0 && cnt > 0) { // 남아있는 화살이 존재할 때 제일 점수가 낮은 점수에 몰빵
            v[flag] += cnt;
        }

        if (asum < rsum && t <= (rsum - asum)) {
            t = rsum - asum;
            answer = v;

        }

    }
    if (t == -1) {
        answer.push_back(-1);
    }

    return answer;
}