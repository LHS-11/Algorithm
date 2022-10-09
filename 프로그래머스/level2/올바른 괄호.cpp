#include<bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char>stk;

    for (auto c : s) {

        if (c == ')')
            if (stk.empty()) {
                answer = false;
                break;
            }
            else stk.pop();
        else stk.push('(');
    }
    if (stk.size()) answer = false;

    return answer;
}