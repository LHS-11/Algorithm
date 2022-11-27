#include<bits/stdc++.h>
using namespace std;
int cnt1[10004], cnt2[10004];
int solution(vector<int> topping) {
    int answer = 0;

    vector<int> t = topping;
    int num1 = 0, num2 = 0;
    for (auto e : t) {
        if (!cnt2[e]) {
            num2++;
        }
        cnt2[e]++;
    }

    for (auto e : t) {
        if (cnt2[e]) {
            cnt2[e]--;
            if (!cnt2[e]) num2--;
        }
        if (!cnt1[e]) {
            cnt1[e]++;
            num1++;
        }
        if (num1 == num2) answer++;
    }


    return answer;
}