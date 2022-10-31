#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    for (int i = 0; i < want.size(); i++) {
        mp[want[i]] = number[i];
    }

    for (int i = 0; i <= discount.size() - 10; i++) {
        map<string, int>mp1 = mp;
        for (int j = i; j < i + 10; j++) {
            if (mp1[discount[j]]) {
                mp1[discount[j]]--;
            }
        }

        int flag = 0;
        for (auto s : want) {
            if (mp1[s]) flag = 1;
        }
        if (!flag) answer++;
    }


    return answer;
}