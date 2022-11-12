#include<bits/stdc++.h>
using namespace std;
int vis[14], answer;
void go(vector<int> number, int idx, int k, int sum) {

    if (k == 3) {
        if (sum == 0) answer++;
        return;
    }

    for (int i = idx; i < number.size(); i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        go(number, i, k + 1, sum + number[i]);
        vis[i] = 0;
    }
}
int solution(vector<int> number) {
    go(number, 0, 0, 0);
    return answer;
}