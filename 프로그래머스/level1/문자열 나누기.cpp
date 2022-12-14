#include<bits/stdc++.h>
using namespace std;
// 카운트 변수 두개를 둬서 계속해서 비교 하는식
int cnt1, cnt2, flag;
int solution(string s) {
    int answer = 0;

    char x = s[0];
    cnt1++;
    for (int i = 1; i < s.size(); i++) {
        if (x == s[i]) {
            cnt1++;
        }
        else {
            cnt2++;
        }
        if (cnt1 == cnt2) {
            answer++;
            x = s[i + 1];
            i++;
            cnt1 = 1;
            cnt2 = 0;

        }
    }
    if (x) answer++;

    return answer;
}