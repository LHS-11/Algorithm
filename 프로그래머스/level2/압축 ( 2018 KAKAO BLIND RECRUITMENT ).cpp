#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
int n;
vector<int> solution(string msg) {
    vector<int> answer;

    for (int i = 0; i <= 25; i++) { // 길이가 1인 단어 mp에 넣어둠
        string s = "";
        s += ('A' + i);
        mp[s] = i + 1;
    }

    int n = 27;
    for (int i = 0; i < msg.size();) { // 알고리즘 작동
        int flag = 0;
        string s = "";
        s += msg[i];
        int j = i;
        while (j < msg.size() && mp[s]) {
            j++;
            s += msg[j];
            flag = 1;
        }
        if (flag) {
            mp[s] = n;
            n++;
            i = j;
        }
        s.pop_back();
        answer.push_back(mp[s]);
    }


    return answer;
}