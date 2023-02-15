#include<bits/stdc++.h>
using namespace std;
vector<int> node[104];
int highCnt[104]; // 각 정점보다 높은 레벨의 정점의 수
int lowCnt[104]; // 각 정점보다 낮은 레벨의 정점의 수
int vis[104];
void go(int n,int cnt[]){
    
     for(int i=1;i<=n;i++){
        
        memset(vis,0,sizeof(vis));
        int visCnt=0;
        queue<int> q;
        q.push(i);
        vis[i]=1;
        
        while(q.size()){
            auto cur =q.front();
            q.pop();
            
            for(int k=0;k<node[cur].size();k++){
                int nxt=node[cur][k];
                if(!vis[nxt]){
                    q.push(nxt);
                    vis[nxt]=1;
                    visCnt++;
                }
            }
        }
        cnt[i]=visCnt;
    }
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    /*
    트리의 레벨을 구하는 문제 
    1. 트리를 구상한다.
    2. 레벨을 설정
    -> 발상의 전환
    결국 한 정점에서 정확하게 순위가 매겨지기 위해서는 높은 레벨의 정점의 수 (이기는 단방향) + 낮은 레벨의 정점의 수 (지는 단방향) + 1 이 n개의 정점이 되어야 한다.
    */

    // 지는 단방향으로 향하는 노드 설정
    for(auto v : results){
        node[v[0]].push_back(v[1]);
    }
    
    // 낮은 레벨의 정점의 수 카운팅
    go(n,lowCnt);
    
    for(int i=1;i<=n;i++){
        node[i].clear();
    }
    
    // 이기는 단방향으로 향하는 노드 설정
    for(auto v : results){
        node[v[1]].push_back(v[0]);
    }
    
    // 높은 레벨의 정점의 수 카운팅
    go(n,highCnt);
   
    // 이기는 단방향) + 낮은 레벨의 정점의 수 (지는 단방향) + 1 == n개의 정점
    for(int i=1;i<=n;i++){
        if(lowCnt[i]+highCnt[i]+1==n) answer++;
    }
    
    return answer;
}