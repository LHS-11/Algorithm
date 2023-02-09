#include<bits/stdc++.h>
using namespace std;
string solution(string s, string skip, int index) {
    string answer = "";
    for(auto c : s){
        
        char ch=c;
        int tmp=index;
        
        while(tmp){
            ch=(ch+1);
            if(ch>'z') ch=(ch-'z'-1)+'a';
            if(skip.find((char)ch)!=string::npos) continue;
            tmp--;
        }
        answer+=ch;
        
    }
    
    return answer;
}