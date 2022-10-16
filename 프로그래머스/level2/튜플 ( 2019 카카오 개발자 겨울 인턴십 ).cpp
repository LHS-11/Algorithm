#include<bits/stdc++.h>
using namespace std;
vector<string> str;
int vis[100004]; 
bool compare(string a, string b) {
    return a.size() < b.size();
}
vector<int> solution(string s) { 
    // 다른 사람 풀이보니깐 나오는 숫자마다 카운팅 시켜서 카운팅이 많은 것이 제일 첫번째에 와야한다는 것을 의미
    vector<int> answer;

    string s1 = "";
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') {
            s1 = "";
        }
        else if (s[i] == '}') {
            str.push_back(s1);
        }
        else {
            s1 += s[i];
        }
    }
    sort(str.begin(), str.end(), compare);


    for (int i = 0; i < str.size(); i++) {
        if (i == 0) {
            answer.push_back(stoi(str[i]));
            vis[stoi(str[i])] = 1;
        }
        else {
            string s2 = "";
            for (auto c : str[i]) {
                if (isdigit(c)) {
                    s2 += c;
                }
                else {
                    if (!vis[stoi(s2)]) {
                        answer.push_back(stoi(s2));
                        vis[stoi(s2)] = 1;
                        s2 = "";
                    }
                    else s2 = "";
                }
            }
            if (!vis[stoi(s2)]) {
                answer.push_back(stoi(s2));
                vis[stoi(s2)] = 1;
            }
        }
    }

    return answer;
}