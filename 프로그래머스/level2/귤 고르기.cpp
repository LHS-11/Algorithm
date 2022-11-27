#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    // 1 2 2 3 3 4 5 5
    vector<int> t = tangerine;
    sort(t.begin(), t.end());


    map<int, int> mp;
    for (auto e : t) {
        mp[e]++;
    }

    for (auto e : t) {
        v.push_back({ mp[e],e });
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = v.size() - 1; i >= 0; i--) {
        int cnt = v[i].first;

        if (k <= 0) break;
        else {
            k -= cnt;
            answer++;
        }
    }


    return answer;
}