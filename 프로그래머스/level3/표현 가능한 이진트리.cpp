#include<bits/stdc++.h>
using namespace std;
bool flag=true;
long long root;
// bool go(string s){
    
//     long long sz=s.size()/2;
//     if(!sz) return true;
    
//     if(s[sz]=='0' && (s[sz-(sz/2+1)]=='1' || s[sz+(sz/2+1)]=='1')) {
//         return false;
//     }
//     bool l=go(s.substr(0,sz));
//     bool r=go(s.substr(sz+1,sz));
//     return l&& r;
// }
void go(string s){
    
    long long sz=s.size()/2;
    if(!sz) return;
    
    if(s[sz]=='0' && (s[sz-(sz/2+1)]=='1' || s[sz+(sz/2+1)]=='1')) {
        flag=false;
        return;
    }
    go(s.substr(0,sz));
    go(s.substr(sz+1,sz));
    return;
}
string change(long long n){
    string str="";
    while(n){
        str+=to_string(n%2);
        n/=2;
    }
    reverse(str.begin(),str.end());
    return str;
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    vector<long long> v;
    
    for(int i=1;i<=50;i++){
        v.push_back(pow(2,i)-1);
    }
    
    for(auto n : numbers){
        flag=true;
        string s=change(n);
        
        long long sz=s.size();
        
        auto it=lower_bound(v.begin(),v.end(),sz);
        long long k=*it;
        k-=sz;
        while(k){
            s="0"+s;
            k--;
        }
        
        
        root=s.size()/2;
        go(s);
        if(flag) answer.push_back(1);
        else answer.push_back(0);
            
    }
    return answer;
}
