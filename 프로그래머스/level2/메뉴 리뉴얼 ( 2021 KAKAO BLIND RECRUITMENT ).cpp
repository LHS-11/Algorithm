#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++) {
        for (int j = i + 1; j < orders.size(); j++) {
            for (auto c : orders[i]) {
                for (auto c1 : orders[j]) {
                    if (c == c1)
                }
            }
        }
    }

    for (auto str : orders) {
        cout << str << ' ' << mp[str] << endl;
    }


    return answer;
}