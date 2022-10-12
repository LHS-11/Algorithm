#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
int solution(string str1, string str2) {
    double ans = 0;
    vector<string> v1, v2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);


    for (int i = 0; i < str1.size() - 1; i++) {

        if (islower(str1[i]) && islower(str1[i + 1])) {
            string s1 = ""; s1 += str1[i]; s1 += str1[i + 1];
            v1.push_back(s1);
        }

    }

    for (int i = 0; i < str2.size() - 1; i++) {
        if (islower(str2[i]) && islower(str2[i + 1])) {
            string s1 = ""; s1 += str2[i]; s1 += str2[i + 1];
            v2.push_back(s1);
        }
    }

    for (auto c : v1) mp[c]++;

    double cnt = 0;
    for (auto c : v2) {
        if (mp[c]) {
            mp[c]--;
            cnt++;
        }
    }
    if (!v1.size() && !v2.size()) {
        ans = 1;
    }
    else {
        ans = v1.size() + v2.size() - cnt;
        ans = cnt / ans;

    }
    return ans * 65536;
}