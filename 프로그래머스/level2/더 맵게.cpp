#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int solution(vector<int> scoville, int K) {
    int answer = 0;

    for (auto c : scoville) q.push(c);

    // priority_queue<int,vector<int>,greater<int>> q(scoville.begin(),scoville.end());


    while (q.size() && q.top() < K) {
        int cur = q.top();
        q.pop();
        if (q.empty()) {
            answer = -1;
            break;
        }
        int nxt = q.top();
        q.pop();

        q.push(cur + nxt * 2);
        answer++;
    }
    return answer;
}