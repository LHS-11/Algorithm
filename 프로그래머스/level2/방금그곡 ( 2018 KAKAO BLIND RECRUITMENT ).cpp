#include<bits/stdc++.h>
using namespace std;
vector<string> music;
string solution(string m, vector<string> musicinfos) {
    string answer = "";

    // musicinfos , 파싱 (시작 시간-끝나는 시간), 음악 제목, 악보 정보
    // 끝나는시간-시작시간 만큼 악보정보를 이어붙이기 
    // 문자열 m을 가지고 find 함수 사용 
    // 존재한 제목과 시간 vector<pair<int,string>> answer에 넣기 
    vector<pair<int, string>> ans;
    for (auto music : musicinfos) {

        int startTime = stoi(music.substr(0, 2)) * 60 + stoi(music.substr(3, 2));
        int endTime = stoi(music.substr(6, 2)) * 60 + stoi(music.substr(9, 2));
        int t = endTime - startTime;

        string s = "";
        string name;
        for (int i = 0; i < music.size(); i++) {
            if (music[i] == ',') {
                name = s;
                s = "";
            }
            else s += music[i];
        }

        int sz = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isupper(s[i])) sz++;
        }

        int idx = 0;
        while (idx < s.size() && sz < t) {
            if (s[idx + 1] == '#') {
                string ss = "";
                ss += s[idx];
                ss += s[idx + 1];
                s += ss;
                idx += 2;
            }
            else {
                s += s[idx];
                idx += 1;
            }
            sz++;
        }
        while (sz > t) {
            if (s[s.size() - 1] == '#') {
                s.pop_back();
                s.pop_back();
            }
            else {
                s.pop_back();
            }
            sz--;
        }

        while (s.find("#") != string::npos) {
            string ss = "";
            ss += s[s.find("#") - 1];
            if (ss == "C") {
                s.replace(s.find("#") - 1, 2, "H");
            }
            else if (ss == "D") {
                s.replace(s.find("#") - 1, 2, "I");

            }
            else if (ss == "F") {
                s.replace(s.find("#") - 1, 2, "J");

            }
            else if (ss == "G") {
                s.replace(s.find("#") - 1, 2, "K");

            }
            else if (ss == "A") {
                s.replace(s.find("#") - 1, 2, "M");
            }
            else if (ss == "B") {
                s.replace(s.find("#") - 1, 2, "N");
            }
        }

        while (m.find("#") != string::npos) {
            string ss = "";
            ss += m[m.find("#") - 1];
            if (ss == "C") {
                m.replace(m.find("#") - 1, 2, "H");
            }
            else if (ss == "D") {
                m.replace(m.find("#") - 1, 2, "I");

            }
            else if (ss == "F") {
                m.replace(m.find("#") - 1, 2, "J");

            }
            else if (ss == "G") {
                m.replace(m.find("#") - 1, 2, "K");

            }
            else if (ss == "A") {
                m.replace(m.find("#") - 1, 2, "M");
            }
            else if (ss == "B") {
                m.replace(m.find("#") - 1, 2, "N");
            }
        }
        if (s.find(m) != string::npos) {
            ans.push_back({ t,name });
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.size()) {
        answer = ans[ans.size() - 1].second;
    }
    else answer = "(None)";


    return answer;
}
