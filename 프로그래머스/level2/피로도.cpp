#include<bits/stdc++.h>
using namespace std;
int vis[9];
int mx;
void go(int cnt, vector<vector<int>> v, int k) {

    if (k >= 0) {
        mx = max(mx, cnt);
    }
    else return;

    for (int i = 0; i < v.size(); i++) {
        if (vis[i] || k < v[i][0]) continue;
        vis[i] = 1;
        k -= v[i][1];
        go(cnt + 1, v, k);
        k += v[i][1];
        vis[i] = 0;

    }
}
int solution(int k, vector<vector<int>> dungeons) {

    go(0, dungeons, k);
    return mx;
}