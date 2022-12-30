#include<bits/stdc++.h>
using namespace std;
int vis[100004];
int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(B.begin(), B.end());
    sort(A.begin(), A.end());

    for (auto a : A) {
        int l = 0;
        int r = B.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (B[m] > a && !vis[m]) {
                r = m - 1;
            }
            else l = m + 1;
        }
        if (!vis[l] && l <= B.size() - 1) {
            answer++;
        }
        vis[l] = 1;

    }

    return answer;
}