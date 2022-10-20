#include<bits/stdc++.h>
using namespace std;
map<string, string> mp;
vector<string> solution(vector<string> record) {
    vector<string> answer;

    for (auto s : record) {

        stringstream stream;
        stream.str(s);
        string ss;
        vector<string> v;
        while (stream >> ss) {
            v.push_back(ss);
        }

        if (v[0][0] == 'E' || v[0][0] == 'C') mp[v[1]] = v[2];
    }

    for (auto s : record) {

        stringstream stream;
        stream.str(s);
        string ss;
        vector<string> v;
        while (stream >> ss) {
            v.push_back(ss);
        }

        string name = mp[v[1]];
        if (v[0][0] == 'E') answer.push_back(name + "님이 들어왔습니다.");
        else if (v[0][0] == 'L') answer.push_back(name + "님이 나갔습니다.");
    }


    return answer;
}