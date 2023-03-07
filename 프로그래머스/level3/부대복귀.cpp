#include<bits/stdc++.h>
using namespace std;
/*
1. 노드 만들기 (map)
2. 각 source 마다 bfs, dfs 돌리기 -> 시간초과 
2. n이 너무 커서 플로이드 와샬 알고리즘 불가능
2. 다익스트라를 destination 을 기준으로 돌리면 시간 안에 가능 
*/
vector<int> node[100005];
int dist[100005];
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    for(auto r : roads){
        node[r[0]].push_back(r[1]);
        node[r[1]].push_back(r[0]);
    }
    
    fill(dist,dist+n+4,INT_MAX);

    queue<int> q;
    q.push(destination);
    dist[destination]=0;
    
    while(q.size()){
        auto cur=q.front();
        q.pop();
        
        for(int i=0;i<node[cur].size();i++){
            int nxt=node[cur][i];
            if(dist[nxt]>dist[cur]+1){
                dist[nxt]=dist[cur]+1;
                q.push(nxt);
            }
        }
    }
    
    for(auto s :sources) {
        if(dist[s]==INT_MAX) answer.push_back(-1);
        else answer.push_back(dist[s]);
    }
    
    return answer;
}