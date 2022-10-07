#include<bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";

    string s1 = "";
    //     for(int i=0;i<s.size();i++){
    //         if(s[i]==' ') {
    //             for(char& c : s1) {
    //                 if(isupper(c)) c=tolower(c);
    //             }
    //             if(islower(s1.front())) s1.front()=toupper(s1.front());
    //             answer+=s1;
    //             answer+=s[i];
    //             s1="";
    //         }
    //         else{
    //             s1+=s[i];
    //         }
    //     }

    //     for(char& c : s1) if(isupper(c)) c=tolower(c);
    //     if(islower(s1.front())) s1.front()=toupper(s1.front());
    //     answer+=s1;

    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); i++) {
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);
    }

    return answer;
}