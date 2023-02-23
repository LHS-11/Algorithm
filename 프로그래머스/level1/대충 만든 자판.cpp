#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int> mp;
    for(auto k : keymap){
        for(int i=0;i<k.size();i++){
            if(mp[k[i]] && mp[k[i]]<=i+1) continue;
            mp[k[i]]=i+1;
        }
    }

    for(auto target : targets){
        int cnt=0,flag=0;
        for(auto t :target) {
            if(mp[t]){
                cnt+=mp[t];
            }else{
                flag=1;
                break;
            }
        }
        if(flag) answer.push_back(-1);
        else answer.push_back(cnt);
    }
    
    return answer;
}