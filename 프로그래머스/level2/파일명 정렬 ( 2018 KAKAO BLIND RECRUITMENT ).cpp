#include<bits/stdc++.h>
using namespace std;
map<string, string> head;
map<string, string> num;
vector<tuple<string, int, int, string>> v;
vector<string> solution(vector<string> files) {
    vector<string> answer;

    for (int i = 0; i < files.size(); i++) {

        string s = "";
        string n = "";
        for (int j = 0; j < files[i].size(); j++) {

            if (isdigit(files[i][j])) {
                head[files[i]] = s;
                n += files[i][j];
            }
            else {
                s += tolower(files[i][j]);
                if (n.size() > 0) {
                    while (n.size() > 5) {
                        n.pop_back();
                    }
                    num[files[i]] = n;
                    n = "";
                    break;
                }
            }
        }
        if (n.size() > 0) num[files[i]] = n;
    }
    int idx = 0;
    for (auto str : files) {
        v.push_back({ head[str],stoi(num[str]),idx,str });
        idx++;
    }
    sort(v.begin(), v.end());
    for (auto t : v) {
        answer.push_back(get<3>(t));
    }


    return answer;
}