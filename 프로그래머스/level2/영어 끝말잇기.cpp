#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    int sz = n;
    int cnt = 1;
    char ch = words[0].front();
    for (int i = 0; i < words.size(); i++) {
        if (mp[words[i]] || ch != words[i].front()) {
            answer.push_back(i % n + 1);
            answer.push_back(cnt);
            break;
        }
        else mp[words[i]]++;

        sz--;
        if (sz == 0) {
            cnt++;
            sz = n;
        }
        ch = words[i].back();
    }

    if (!answer.size()) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}