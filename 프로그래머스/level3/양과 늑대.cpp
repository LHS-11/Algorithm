#include<bits/stdc++.h>
using namespace std;
/*
최대한 많은 양을 먹고 나서 늑대를 먹음으로써 커버치면서 먹을 수 있는 양을 구하는 것
=> 양이 늑대보다는 항상 많아야 한다!, 완탐 (dfs)
1. 현재 노드에 어떤 동물인지 확인하고 sh,wf 카운팅
2. answer 갱신
3. sh<=wf 이라면 return
4. 현재 노드에서 다음으로 방문할 수 있는 노드를 for문 돌기
5. for문 돌면서 현재 방문한 노드는 삭제하고 다음 방문할 수 있는 리스트 넣기 
*/
vector<int> v[18];
vector<int> sts;
int ans;
void go(int now,int sh,int wf,vector<int> lst){
    
    if(!sts[now]) sh++;
    else wf++;
    
    ans=max(ans,sh);
    
    if(wf>=sh) return;
    
    for(int i=0;i<lst.size();i++){
        vector<int> nxt=lst;
        
        // 방문할 수 있는 곳들에서 다음 방문할 곳 삭제
        nxt.erase(find(nxt.begin(),nxt.end(),lst[i]));
        
        // 다음 방문할 곳의 자식 노드들 넣기
        for(int j=0;j<v[lst[i]].size();j++){
            nxt.push_back(v[lst[i]][j]);
        }
        
        // dfs 호출 
        go(lst[i],sh,wf,nxt);
    }
    
    
}
int solution(vector<int> info, vector<vector<int>> edges) {
    
    sts=info;
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> v1;
    for(int i=0;i<v[0].size();i++) v1.push_back(v[0][i]);
    go(0,0,0,v1);
    return ans;
}
/*
#include<bits/stdc++.h>
using namespace std;
int ans;
vector<int> v[20];
void go(int now,int sh,int wf,vector<int> node,vector<int>& info){
    if(!info[now]) sh++;
    else wf++;
    if(wf>=sh) return;
    ans=max(sh,ans);
    node.erase(find(node.begin(),node.end(),now));
    for(auto e : v[now]) node.push_back(e);
    for(auto n : node) go(n,sh,wf,node,info);
    
}
int solution(vector<int> info, vector<vector<int>> edges) {
    
    for(auto e :edges){
        v[e[0]].push_back(e[1]);
    }
    go(0,0,0,{0},info);
    
    
    return ans;
}
*/