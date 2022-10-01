#include<bits/stdc++.h>
using namespace std;
string answer = "";
bool chk(char c) { // 대문자 체킹
    if (c >= 'A' && c <= 'Z') return true;
    else return false;
}
void change(string s1) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != ' ') {
            if (i % 2 == 0) {
                if (!chk(s1[i])) answer += (char)s1[i] - 'a' + 'A';
                else answer += s1[i];
            }
            else {
                if (chk(s1[i])) answer += (char)s1[i] - 'A' + 'a';
                else answer += s1[i];
            }
        }
        else {
            answer += ' ';
        }
    }
}
string solution(string s) {

    string s2 = "";
    string s3 = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            s3 += s[i];
            change(s2);
            s2 = "";
        }
        else {
            s2 += s[i];
            answer += s3;
            s3 = "";
        }
    }
    if (s2.size()) {
        change(s2);
    }
    else {
        answer += s3;
    }
    return answer;
}