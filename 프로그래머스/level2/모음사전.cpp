#include<bits/stdc++.h>
using namespace std;
string s[5] = { "A","E","I","O","U" };
vector<string> ans;
void go(int sz, string ss) {
    if (sz == ss.size()) {
        ans.push_back(ss);
        return;
    }

    for (int i = 0; i < 5; i++) {
        go(sz, ss + s[i]);
    }
    return;
}
int solution(string word) {
    int answer = 0;

    for (int i = 1; i <= 5; i++) {
        go(i, "");
    }

    sort(ans.begin(), ans.end());

    answer = find(ans.begin(), ans.end(), word) - ans.begin() + 1;

    return answer;
}