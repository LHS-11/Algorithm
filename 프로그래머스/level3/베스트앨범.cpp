#include<bits/stdc++.h>
using namespace std;
bool cmp(tuple<string, int, int> p1, tuple<string, int, int> p2) {
    string a, d;
    int b, c, e, f;
    tie(a, b, c) = p1;
    tie(d, e, f) = p2;

    if (a == d) {
        return b > e;
    }
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // 1. 속한 노래가 많이 재생된 장르 먼저 수록 ( 장르별로 숫자를 다 더해서 구분 )
    map<string, int> mp;
    vector<tuple<string, int, int>> v;
    for (int i = 0; i < plays.size(); i++) {
        v.push_back({ genres[i],plays[i],i });
        mp[genres[i]] += plays[i];
    }

    priority_queue<pair<int, string>> pq;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        pq.push({ iter->second,iter->first });
    }

    // 2. 장르 내에서 많이 재생된 노래 먼저 수록 ( 노래 재생 횟수 만큼 )
    sort(v.begin(), v.end(), cmp);
    while (pq.size()) {
        auto cur = pq.top();
        pq.pop();
        int cnt = 0;

        for (int i = 0; i < v.size(); i++) {
            int b, c; string a;
            tie(a, b, c) = v[i];
            if (cur.second == a) {
                answer.push_back(c);
                cnt++;
            }
            if (cnt == 2) break;
        }
    }


    // 3. 재생 횟수가 같은 노래 중에서 고유 번호가 낮은 노래 먼저 수록
    return answer;
}