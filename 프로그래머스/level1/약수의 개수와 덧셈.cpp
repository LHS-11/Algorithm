#include<bits/stdc++.h>
using namespace std;
bool go(int n) {
    int cnt = 0;
    if (n == 1) cnt += 1;
    else cnt += 2;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (n == i * i) cnt += 1;
            else cnt += 2;
        }
    }
    if (cnt % 2 == 0) return true;
    else return false;

}
int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (go(i)) answer += i;
        else answer -= i;
    }

    return answer;
}