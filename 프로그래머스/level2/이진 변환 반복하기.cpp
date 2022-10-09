#include<bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {

    vector<int> answer;

    int zeroCnt = 0, cnt = 0;
    while (s != "1") {
        int sz = 0;
        for (auto c : s) {
            if (c != '0') sz++;
            else zeroCnt++;
        }

        s = "";
        while (sz) {
            s = s + to_string(sz % 2);
            sz /= 2;
        }
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(zeroCnt);

    return answer;
}