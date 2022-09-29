#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    if (begin == 1) {
        answer.push_back(0);
        begin++;
    }

    for (ll st = begin; st <= end; st++) {
        ll rst = 1;
        for (ll i = 1; i * i <= st; i++) {
            if (i != 1 && st % i == 0 && (st / i) <= 10000000) {
                rst = max(rst, st / i);
            }
        }
        answer.push_back(rst);
    }

    return answer;
}