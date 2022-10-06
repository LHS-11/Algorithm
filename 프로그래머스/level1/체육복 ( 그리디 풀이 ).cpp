#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int lst[31];
int rsv[31];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (auto c : lost) lst[c]++;
    for (auto c : reserve) {
        if (lst[c]) lst[c]--;
        else rsv[c]++;
    }

    for (auto c : lost) {
        if (lst[c]) v.push_back(c);
    }

    for (auto c : v) {
        if (rsv[c - 1]) {
            rsv[c - 1]--;
            lst[c]--;
        }
        else if (rsv[c + 1]) {
            rsv[c + 1]--;
            lst[c]--;
        }
    }

    answer = n;
    for (int i = 1; i <= n; i++) {
        if (lst[i]) answer--;
    }

    return answer;
}