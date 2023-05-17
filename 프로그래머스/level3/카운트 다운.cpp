#include<bits/stdc++.h>
using namespace std;
/*
구현 문제 
가장 적게 던질 다트 수와 싱글 또는 불을 맞춘 횟수(합) 구하는 문제 
*/
#define INF 1e9
int score[61];
map<int,pair<int,int>> mp;
vector<int> solution(int target) {
    vector<int> answer;
    
    score[0]=50;
    
    for(int i=1;i<=3;i++){
        int k=1;
        for(int j=1+((i-1)*20);j<=20+((i-1)*20);j++,k++){
            score[j]=i*k;
        }
    }
    
    for(int i=1;i<=target;i++){
        mp[i]={INF,0};
    }
    
    for(int i=0;i<=60;i++){
        if(i<=20) mp[score[i]]={1,1};
        else {
            auto cur=mp[score[i]];
            if(cur.first==1 && cur.second>0) continue;
            mp[score[i]]={1,0};
        }
    }
    
    for(int i=1;i<=target;i++){
        for(int j=0;j<=60;j++){
            if(i>=score[j]){
                
                if(mp[i].first>mp[i-score[j]].first+1){
                    
                    if(j<=20) mp[i]={mp[i-score[j]].first+1,mp[i-score[j]].second+1};
                    else mp[i]={mp[i-score[j]].first+1,mp[i-score[j]].second};
                    
                }else if(mp[i].first==mp[i-score[j]].first+1){
                    if(j<=20){
                        mp[i].second=max(mp[i].second,mp[i-score[j]].second+1);
                    }else{
                        mp[i].second=max(mp[i].second,mp[i-score[j]].second);
                    }
                }
            }
        }
    }
    
    return {mp[target].first,mp[target].second};
}