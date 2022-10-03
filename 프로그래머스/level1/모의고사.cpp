#include<bits/stdc++.h>
using namespace std;
int chk1[] = { 1,2,3,4,5 }; // 5, 8 , 10
int chk2[] = { 2,1,2,3,2,4,2,5 };
int chk3[] = { 3,3,1,1,2,2,4,4,5,5 };
int sum[4];
struct compare { // priority_queue 커스텀의 경우 => 일반 compare 함수와 반대로 return 설정 해야함
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
vector<int> solution(vector<int> answers) {
    vector<int> answer;

    for (int i = 0; i < answers.size(); i++) {

        if (chk1[i % 5] == answers[i]) sum[1]++;
        if (chk2[i % 8] == answers[i]) sum[2]++;
        if (chk3[i % 10] == answers[i]) sum[3]++;
    }

    for (int i = 1; i <= 3; i++) {
        pq.push({ sum[i],i });
    }

    // priority_queue를 사용할 필요 없이 최대값을 구한 뒤 최대값이랑 같을 때만 answer에 push 하면 됨!

    int mx = 0;
    while (pq.size()) {
        if (mx <= pq.top().first) {
            mx = pq.top().first;
            answer.push_back(pq.top().second);
        }
        pq.pop();
    }

    return answer;
}