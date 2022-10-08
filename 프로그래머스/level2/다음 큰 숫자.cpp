#include<bits/stdc++.h>
using namespace std;
int cnt[2], cnt1[2];
bool go(int k) { // 그냥 이진법 변환
    while (k) {
        cnt1[k % 2]++;
        k /= 2;
    }
    if (cnt1[1] == cnt[1]) return true;

    else return false;
}
bool go1(int k) { // 비트마스킹 이용
    for (int i = 0; i < 31; i++) {
        if (k & (1 << i)) cnt1[1]++;
    }
    if (cnt1[1] == cnt[1]) return true;

    else return false;
}
int solution(int n) {
    int answer = 0;

    int x = n;
    while (x) {
        cnt[x % 2]++;
        x /= 2;
    }

    for (int i = n + 1; i <= 1000000; i++) {
        if (go1(i)) {
            answer = i;
            break;
        }
        cnt1[1] = 0;
    }
    return answer;
}