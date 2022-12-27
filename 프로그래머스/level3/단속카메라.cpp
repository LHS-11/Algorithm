#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> r1, vector<int> r2) {
    if (r1[1] == r2[1]) {
        return r1[0] < r2[0];
    }
    return r1[1] < r2[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), cmp);

    int st = routes[0][1];
    answer++;
    for (int i = 1; i < routes.size(); i++) {
        if (st < routes[i][0]) {
            st = routes[i][1];
            answer++;
        }
    }

    return answer;
}
