#include<bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    // 큰 수를 계속 줄여야 함 
    sort(works.begin(), works.end());

    int mx = works[works.size() - 1];

    while (n--) {
        int idx = lower_bound(works.begin(), works.end(), mx) - works.begin();
        works[idx]--;
        if (idx == works.size() - 1) {
            mx = works[idx];
        }
    }

    for (auto w : works) {
        if (w <= 0) continue;
        answer += (w * w);
    }


    return answer;
}