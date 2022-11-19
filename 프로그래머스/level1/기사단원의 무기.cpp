#include<bits/stdc++.h>
using namespace std;
int go(int k) {
    int cnt = 0;

    for (int i = 1; i * i <= k; i++) {
        if (k % i != 0) continue;
        if (i * i == k) {
            cnt++;
        }
        else cnt += 2;
    }
    return cnt;
}
int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; i++) {
        int n = go(i);
        if (n > limit) {
            answer += power;
        }
        else answer += n;
    }

    return answer;
}