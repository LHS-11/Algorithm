#include<bits/stdc++.h>
using namespace std;
int sz;
map<string, int> out_cnt;
map<string, int> in_cnt;
set<string> s;
set<string> in;
vector<int> solution(vector<string> gems) {
    vector<tuple<int, int, int>> ans;

    for (auto gem : gems) {
        out_cnt[gem]++;
        s.insert(gem);
    }

    sz = s.size();

    int st, en = 0;
    for (st = 0; st < gems.size(); st++) {

        // 투포인터 en 범위를 보석의 모든 종류를 포함할 때까지 늘림 
        while (in.size() != sz && en < gems.size()) {
            if (out_cnt[gems[en]]) {
                out_cnt[gems[en]]--;
            }
            in_cnt[gems[en]]++;
            in.insert(gems[en]);
            en++;
        }

        // st~en 사이에 모든 보석이 존재할 때
        if (in.size() == sz) {
            ans.push_back({ en - st,st + 1,en });
        }

        // 이제 st를 조정해서 범위를 줄임
        in_cnt[gems[st]]--;
        out_cnt[gems[st]]++;

        if (!in_cnt[gems[st]]) {
            in.erase(gems[st]);
        }

    }

    sort(ans.begin(), ans.end());
    return { get<1>(ans[0]),get<2>(ans[0]) };
}