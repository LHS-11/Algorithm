#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    for (auto c : completion) {
        mp[c]++;
    }

    for (auto c : participant) {
        if (!mp[c]) {
            answer = c;
            break;
        }
        else {
            mp[c]--;
        }
    }
    return answer;
}