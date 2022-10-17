#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
queue<pair<int, int>> q;
int solution(vector<int> priorities, int location) {
    int ans = 1;

    for (auto c : priorities) pq.push(c);

    for (int i = 0; i < priorities.size(); i++) q.push({ priorities[i],i });

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        if (cur.first >= pq.top()) {
            pq.pop();
            if (cur.second == location) {
                break;
            }
            ans++;
        }
        else {
            q.push({ cur.first,cur.second });
        }

    }


    return ans;
}