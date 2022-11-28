#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> order) {
    int answer = 0;

    stack<int> stk;
    int st = 1, i = 0;

    while (1) {
        if (st == order[i]) {
            i++;
            st++;
            answer++;
        }
        if (st > order[i]) {
            int flag = 0;
            while (stk.size() && stk.top() == order[i]) {
                stk.pop();
                answer++;
                i++;
                flag = 1;
            }
            if (!flag) break;
        }
        else if (st < order[i]) {
            stk.push(st);
            st++;
        }
        if (st > order.size()) break;
    }

    //stack<int> stk;

    //int i = 0;
    //for (int st = 1; st <= order.size(); st++) {
    //    stk.push(st);

    //    while (stk.size() && stk.top() == order[i]) {
    //        stk.pop();
    //        i++;
    //        answer++;
    //    }
    //}

    return answer;
}