#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    map<pair<int, int>, int> mp;
    for (int i = 0; i < data.size(); i++) {
        mp[{data[i][col - 1], data[i][0]}] = i;
        v.push_back({ data[i][col - 1],data[i][0] });
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = row_begin - 1; i <= row_end - 1; i++) {
        int rst = 0;
        int idx = mp[{v[i].first, v[i].second}];
        for (int j = 0; j < data[0].size(); j++) {
            rst += (data[idx][j] % (i + 1));
        }
        answer ^= rst;
    }


    return answer;
}