#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int y[10004];
map<int, double> area;
void go(int k, int cnt) {
    if (k == 1) {
        return;
    }

    if (k % 2 == 0) {
        v.push_back({ cnt + 1,k / 2 }); // 3, 8 4 4 5 2
        go(k / 2, cnt + 1);
    }
    else {
        v.push_back({ cnt + 1,k * 3 + 1 }); // 2, 16
        go(k * 3 + 1, cnt + 1);
    }
    return;
}
vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    v.push_back({ 0,k });
    go(k, 0);

    int st = 0;
    int en = v[v.size() - 1].first;

    for (auto x : v) {
        y[x.first] = x.second;
    }

    area[0] = 0;
    for (int i = 1; i <= en; i++) {
        double sum = (y[i] + y[i - 1]) * 0.5;
        area[i] = area[i - 1] + sum;
    }

    for (auto x : ranges) {
        int a = x[0];
        int b = x[1];

        int s = 0, e = en;
        s += a;
        e += b;

        if (s > e) {
            answer.push_back(-1.0);
        }
        else {
            answer.push_back(area[e] - area[s]);
        }

    }


    return answer;
}