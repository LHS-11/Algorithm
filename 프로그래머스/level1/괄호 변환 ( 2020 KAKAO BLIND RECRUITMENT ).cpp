#include<bits/stdc++.h>
using namespace std;
vector<string> go(string k) {
    string u = "", v = "";

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < k.size(); i++) {
        if (k[i] == '(') {
            cnt1++;
        }
        else cnt2++;

        u += k[i];
        if (cnt1 == cnt2) {
            v = k.substr(i + 1, k.size() - i - 1);
            break;
        }
    }

    vector<string> s(2);
    s[0] = u;
    s[1] = v;
    return s;
}
bool check(string k) {
    stack<char> stk;
    int flag = 0;
    for (int i = 0; i < k.size(); i++) {
        if (k[i] == '(') {
            stk.push(k[i]);
        }
        else {
            if (stk.empty()) {
                flag = 1;
                break;
            }
            stk.pop();
        }
    }
    if (!stk.empty()) flag = 1;
    return !flag;
}
string solution(string p) {

    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if (p.empty()) return "";

    string answer = "";


    vector<string> s = go(p);

    string u, v;
    u = s[0];
    v = s[1];
    // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
    // 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
    if (check(u)) {
        answer = u + solution(v);
    }
    //4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
    else {

        //4 - 1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
        //4 - 2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
        //4 - 3. ')'를 다시 붙입니다.
        answer = "(" + solution(v) + ")";

        //4 - 4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        for (int i = 1; i < u.size() - 1; i++) {
            answer += (u[i] == '(' ? ')' : '(');
        }
    }

    return answer;

}