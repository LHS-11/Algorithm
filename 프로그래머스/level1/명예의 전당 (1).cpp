#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    for (auto s : score) {
        q.push(s);
        if (q.size() > k) q.pop();
        answer.push_back(q.top());
    }


    return answer;
}