#include<bits/stdc++.h>
using namespace std;
void go(vector<vector<int>>& v, int k, int st, int en) {

    if (k == 1) {
        v.push_back({ st,en });
        return;
    }

    go(v, k - 1, st, 6 - st - en);
    v.push_back({ st,en });
    go(v, k - 1, 6 - st - en, en);


}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    go(answer, n, 1, 3);

    return answer;
}