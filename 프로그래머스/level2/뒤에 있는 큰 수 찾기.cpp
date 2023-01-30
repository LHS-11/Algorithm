#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    answer.resize(numbers.size());

    stack<pair<int, int>> stk;
    stk.push({0, numbers[0]});

    for (int i = 1; i < numbers.size(); i++)
    {

        auto idx = stk.top().first;
        auto n = stk.top().second;

        while (n < numbers[i])
        {
            answer[idx] = numbers[i];
            stk.pop();
            if (stk.empty())
                break;
            idx = stk.top().first;
            n = stk.top().second;
        }

        stk.push({i, numbers[i]});
    }

    while (stk.size())
    {
        answer[stk.top().first] = -1;
        stk.pop();
    }

    return answer;
}