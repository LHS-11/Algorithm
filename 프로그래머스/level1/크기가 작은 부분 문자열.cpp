#include<bits/stdc++.h>
using namespace std;
int solution(string t, string p) {
    int answer = 0;
    int sz = p.size();

    for (int i = 0; i <= t.size() - sz; i++) {
        string s = t.substr(i, sz);
        if (p >= s) answer++;
    }

    return answer;
}