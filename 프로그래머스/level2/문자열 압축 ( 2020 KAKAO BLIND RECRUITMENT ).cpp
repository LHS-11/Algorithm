#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int solution(string s) {
    int answer = INT_MAX;

    for (int i = 1; i <= s.size(); i++) {

        string ans = "";
        int cnt = 1;

        string s1 = s.substr(0, i);
        for (int j = i; j < s.size(); j += i) {
            string s2 = s.substr(j, i);
            if (s1 == s2) {
                cnt++;
            }
            else {
                if (cnt >= 2) ans += to_string(cnt) + s1;
                else ans += s1;
                s1 = s.substr(j, i);
                cnt = 1;
            }
        }
        if (cnt >= 2) ans += to_string(cnt) + s1;
        else ans += s1;

        int sz = ans.size();
        answer = min(answer, sz);

    }
    return answer;

}