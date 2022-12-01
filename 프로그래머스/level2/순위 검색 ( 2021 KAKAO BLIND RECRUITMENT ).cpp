#include<bits/stdc++.h>
using namespace std;
map<string, vector<int>> mp;
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    // 1. 나올 수 있는 경우의 수 해싱 테이블에 저장
    for (auto str : info) {
        string s[4], score;
        istringstream iss(str);
        iss >> s[0] >> s[1] >> s[2] >> s[3] >> score;

        for (int i = 0; i < 16; i++) {
            string ss = "";
            for (int j = 0; j < 4; j++) {
                ss += (i & (1 << j)) ? "-" : s[j];
            }
            mp[ss].push_back(stoi(score));
        }
    }

    // 2. 해싱 테이블 정렬
    for (auto it = mp.begin(); it != mp.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    // 3. query 문자열 파싱
    for (auto str : query) {
        stringstream stream;
        stream.str(str);

        string s;
        vector<string> ans;
        while (stream >> s) {
            if (s != "and") {
                ans.push_back(s);
            }
        }
        string ss = "";
        for (int i = 0; i < ans.size() - 1; i++) {
            ss += ans[i];
        }
        int score = stoi(ans[ans.size() - 1]);
        // 4. 해싱 테이블에서 이분탐색 진행
        int findCnt = mp[ss].end() - lower_bound(mp[ss].begin(), mp[ss].end(), score);

        answer.push_back(findCnt);
    }
    return answer;
}