#include<bits/stdc++.h>
using namespace std;
map<char, int> rank;
long long cal(long long a, long long b, char c) {
    if (c == '+') return a + b;
    else if (c == '-') return a - b;
    else return a * b;
}
long long solution(string expression) {
    long long answer = 0;

    vector<char> v = { '*','+','-' };
    sort(v.begin(), v.end());

    vector<long long> num;
    vector<char> exp;

    string s = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            exp.push_back(expression[i]);
            num.push_back(stoll(s));
            s = "";
        }
        else {
            s += expression[i];
        }
    }
    num.push_back(stoll(s));

    do {

        vector<long long> ans = num;
        vector<char> ex = exp;

        for (auto c : v) {
            int flag = 0;
            for (int i = 0; i < ex.size();) {
                if (c == ex[i]) {
                    long long rst = cal(ans[i], ans[i + 1], c);
                    ans.erase(ans.begin() + i, ans.begin() + i + 2);
                    ans.insert(ans.begin() + i, rst);
                    ex.erase(ex.begin() + i);
                }
                else {
                    i++;
                }
            }
        }

        answer = max(answer, abs(ans[0]));
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}
