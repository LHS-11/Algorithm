#include<bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int curW = 0; // 현재 다리에 있는 트럭 무게
    int idx = 0;
    queue<int> q;

    while (1) {

        if (idx == truck_weights.size()) {

            answer += bridge_length;

            break;
        }

        int t = truck_weights[idx];
        answer++;

        if (q.size() == bridge_length) { // 현재 다리에 있는 트럭이 나갈 시간이 됨
            curW -= q.front();
            q.pop();
        }

        if (curW + t > weight) {
            q.push(0);
        }
        else {
            curW += t;
            q.push(t);
            idx++;
        }



    }



    return answer;
}