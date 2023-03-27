#include<bits/stdc++.h>
using namespace std;
/*
출발 지점에서 최소 가중치를 가지는 노드로 이동해서 도착지에 도착 
산봉우리의 번호를 저장 
*/
int vis[50004];
int node[50004];
vector<pair<int,int>> v[50004];
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> dis(n+1);
    
    for(auto gt:gates) node[gt]=1;
    for(auto smt:summits) node[smt]=2;
    
    for(auto p :paths){
        v[p[0]].push_back({p[1],p[2]});
        v[p[1]].push_back({p[0],p[2]});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto g:gates){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        fill(dis.begin(),dis.end(),INT_MAX);
        dis[g]=0;
        q.push({0,g});
        while(q.size()){
            auto cur=q.top();
            q.pop();
            
            if(2==node[cur.second]){
                pq.push({cur.first,cur.second});
                continue;
            }
            
            if(pq.size() && pq.top().first<cur.first) continue;
            
            for(int i=0;i<v[cur.second].size();i++){
                int nxt=v[cur.second][i].first;
                int cost=v[cur.second][i].second;
                
                if(node[nxt]==1) continue;
                
                if(dis[nxt]>cost){
                    dis[nxt]=cost;
                    q.push({max(dis[nxt],cur.first),nxt});
                }
            }
            
        }
    }
    
    return {pq.top().second,pq.top().first};
}