#include<bits/stdc++.h>
using namespace std;
vector<int> node[50004];
int vis[50004];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(auto e : edge){
        node[e[0]].push_back(e[1]);
        node[e[1]].push_back(e[0]);
    }
    
    queue<int> q;
    q.push(1);
    
    int mx=0;
    while(q.size()){
        auto cur=q.front();
        q.pop();
        
        for(int i=0;i<node[cur].size();i++){
            int nxt=node[cur][i];
            if(!vis[nxt]){
                vis[nxt]=vis[cur]+1;
                q.push(nxt);
                mx=max(mx,vis[nxt]);
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(vis[i]==mx){
            answer++;
        }
    }
    
    
    return answer;
}