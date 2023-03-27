#include<bits/stdc++.h>
using namespace std;
/*
문자열 파싱 문제 
*/
map<long long,long long>mp;
int toDouble(string s){
    string h="";
    h+=s[0];
    h+=s[1];
    string m="";
    m+=s[3];
    m+=s[4];
    string ss=s.substr(6);
    double t=stod(h)*60*60;
    t+=stod(m)*60;
    t*=1000;
    t+=stod(ss)*1000;
    return t;
}
int solution(vector<string> lines) {
    int answer = 0;
    
    vector<pair<int,int>> v;
    for(auto l : lines){
        
        string t=l.substr(11);
        string s=t.substr(13);
        s.pop_back();
        int time=toDouble(t);
        int second=stod(s)*1000;
        v.push_back({time-second+1,time});
    }
    
    
    for(int i=0;i<v.size();i++){
        int st=v[i].first;
        int en=v[i].second;
        int cnt=1;
        for(int j=i+1;j<v.size();j++){
            if(en+999>=v[j].first){
                cnt++;
            }
        }
        answer=max(answer,cnt);
    }
    
    
    return answer;
}