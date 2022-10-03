#include<bits/stdc++.h>
using namespace std;
string chk[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
int solution(string s) {
    int answer = 0;

    string ans = "";
    string s1 = "";
    for (auto c : s) {
        if (c >= 'a' && c <= 'z') {
            s1 += c;
            for (int i = 0; i < 10; i++) {
                if (chk[i] == s1) {
                    ans += to_string(i);
                    s1 = "";
                    break;
                }
            }
        }
        else ans += c;
    }
    answer = stoi(ans);

    // 정규식 만들어서 하는 방법
    // s = regex_replace(s, regex("zero"), "0");
    // s = regex_replace(s, regex("one"), "1");
    // s = regex_replace(s, regex("two"), "2");
    // s = regex_replace(s, regex("three"), "3");
    // s = regex_replace(s, regex("four"), "4");
    // s = regex_replace(s, regex("five"), "5");
    // s = regex_replace(s, regex("six"), "6");
    // s = regex_replace(s, regex("seven"), "7");
    // s = regex_replace(s, regex("eight"), "8");
    // s = regex_replace(s, regex("nine"), "9");    

    // regex r;
    // for(int i = 0; i < numbers.size(); i++) {
    //     r = numbers[i];
    //     s = regex_replace(s, r, to_string(i));
    // }
    // answer = stoi(s);

    return answer;
}