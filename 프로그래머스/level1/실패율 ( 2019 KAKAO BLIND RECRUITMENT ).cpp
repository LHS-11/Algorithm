#include<bits/stdc++.h>
using namespace std;
double cnt[504];
bool compare(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    for (auto c : stages) {
        cnt[c]++;
    }

    double sz = stages.size();
    vector<pair<double, int>> ans;
    for (int i = 1; i <= N; i++) {
        if (sz <= 0) ans.push_back({ 0,i }); // 실패율이 0 일때가 분자가 0 뿐 아니라 분모가 0일때도 존재
        else ans.push_back({ cnt[i] / sz,i });
        sz -= cnt[i];
    }

    sort(ans.begin(), ans.end(), compare);

    for (auto c : ans) {
        answer.push_back(c.second);
    }

    return answer;
}