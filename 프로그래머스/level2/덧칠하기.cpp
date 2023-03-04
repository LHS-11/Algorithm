#include<bits/stdc++.h>
using namespace std;
/*
최소 부터 + m -> 최소+ m 
*/
int vis[100004];
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int mn=section[0]; // 1. 가장 작은 섹션 값 선택 
    while(1){ // nlogn 풀이 
        auto idx=lower_bound(section.begin(),section.end(),mn+m); // 2. 현재 구역부터 총 m 개의 페인트 칠해졌으니, 다음 구역을 lower_bound로 log N에 구하기 
        
        // answer++; // 페인트칠 카운트 
        
        if(idx==section.end()) break; // 이미 다 칠했으면 탈출 
        
        mn=*idx; // 바로 다음에 남아 있는 구역으로 초기화
    }
    
    // O(n) 풀이
    for(auto s :section){
        vis[s]=1;
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        i+=(m-1);
        answer++;
    }
    
    return answer;
}