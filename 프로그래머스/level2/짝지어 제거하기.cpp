#include<bits/stdc++.h>
using namespace std;
int solution(string s)
{
    int answer = -1;

    stack<int> stk;

    for (auto c : s) {
        if (stk.empty()) {
            stk.push(c);
        }
        else {
            if (stk.top() == c) {
                stk.pop();
            }
            else stk.push(c);
        }
    }

    if (stk.size()) answer = 0;
    else answer = 1;

    return answer;
}