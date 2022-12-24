#include<bits/stdc++.h>
using namespace std;
int cnt, nCnt;
priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;
vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (auto o : operations) {
        if (o[0] == 'I') {
            nCnt++;
            max_pq.push(stoi(o.substr(2, o.size() - 2)));
            min_pq.push(stoi(o.substr(2, o.size() - 2)));

        }
        else {
            if (min_pq.empty() | max_pq.empty()) continue; // 연산 무시
            if (o == "D 1") { // 최대 삭제
                max_pq.pop();
            }
            else { // 최소 삭제
                min_pq.pop();
            }
            cnt++;
            if (cnt == nCnt) { // 초기화
                while (max_pq.size()) {
                    max_pq.pop();
                }
                while (min_pq.size()) {
                    min_pq.pop();
                }
            }
        }
    }
    if (cnt == nCnt) {
        while (max_pq.size()) {
            max_pq.pop();
        }
        while (min_pq.size()) {
            min_pq.pop();
        }
    }

    if (max_pq.empty() && min_pq.empty()) {
        answer = { 0,0 };
    }
    else {
        answer = { max_pq.top(),min_pq.top() };
    }


    return answer;
}