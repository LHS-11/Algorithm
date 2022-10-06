#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int lst[31];
int rsv[31];
int ans = 0;
void go(int idx, int sz, int n) {
    if (idx == sz) {
        int answer = n;
        for (int i = 1; i <= n; i++) {
            cout << lst[i] << ' ';
            if (lst[i]) answer--;
        }
        cout << endl;
        ans = max(ans, answer);
        return;
    }

    if (v[idx] - 1 >= 1 && rsv[v[idx] - 1]) { // 왼쪽부터 확인 해야함
        rsv[v[idx] - 1]--;
        lst[v[idx]]--;
        go(idx + 1, sz, n);
        lst[v[idx]]++;
        rsv[v[idx] - 1]++;
    }
    else if (v[idx] + 1 <= n && rsv[v[idx] + 1]) {
        rsv[v[idx] + 1]--;
        lst[v[idx]]--;
        go(idx + 1, sz, n);
        lst[v[idx]]++;
        rsv[v[idx] + 1]++;
    }
    go(idx + 1, sz, n);

    return;
}
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

    go(0, v.size(), n);

    return ans;
}