#include<bits/stdc++.h>
using namespace std;
bool go(int k, vector<int> v) {
    int cnt = 0;
    for (auto c : v) {
        if (c >= k) cnt++;
    }
    if (cnt < k) return true;
    else return false;
}
int solution(vector<int> citations) {
    int answer = 0;

    int l = 0, r = 10004;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (go(m, citations)) {
            r = m - 1;
        }
        else {
            l = m + 1;
            answer = max(answer, m);
        }
    }

    return answer;
}