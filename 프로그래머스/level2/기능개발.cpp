#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<pair<int, int>>v;

    for (int i = 0; i < progresses.size(); i++) {
        for (int j = 1; j < 100; j++) {
            if (progresses[i] + j * speeds[i] >= 100) {
                v.push_back({ i,j });
                break;
            }
        }
    }

    sort(v.begin(), v.end());

    for (auto c : v) {
        if (pq.empty()) pq.push(c.second);
        else {
            if (pq.top() < c.second) {
                answer.push_back(pq.size());
                while (pq.size()) pq.pop();
                pq.push(c.second);
            }
            else {
                pq.push(c.second);
            }
        }
    }
    answer.push_back(pq.size());
    return answer;

}