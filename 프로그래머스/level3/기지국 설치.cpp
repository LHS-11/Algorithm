#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int answer;
int solution(int n, vector<int> stations, int w)
{

    // 1. 원래 설치된 기지국 범위 제외하기
    int l=1,r=1;
    
    vector<int> v;
    for(auto s :stations){
        r=s-w;
        if(r-l>0){
            v.push_back(r-l);            
        }
        l=s+w+1;  
    }
    if(l<=n){
        v.push_back(n-l+1);
    }
    
    // 2. 남은 공간 구하기 
    for(auto c : v){
        answer+=c/(2*w+1);
        if(c%(2*w+1)!=0){
            answer++;
        }
    }
    
    
    return answer;
}