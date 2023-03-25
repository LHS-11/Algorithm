#include <string>
#include <vector>
#include<iostream>
#include <numeric>
#include<string.h>
using namespace std;
/*
모든 노드의 합이 0인지 확인 아니라면 
길이가 30만이기 때문에 완전 탐색 X 

*/
/*
long long dfs(vector<int>& a, int ind) {
    long long sum = a[ind];
    check[ind] = true;
    for(auto next: edges[ind]){
        if(check[next]) continue;
        long long child = dfs(a, next);
        answer += abs(child);
        sum += child;
    }
    return sum;
}
*/
void dfs(int now){
    
    for(int i=0;i<node[now].size();i++){
        if(vis[node[now][i]]) continue;
        vis[node[now][i]]=1;
        dfs(node[now][i]);
        ans+=abs(sum[node[now][i]]);
        sum[now]+=sum[node[now][i]];
        sum[node[now][i]]=0;
    }
    
}
long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -2;
    
    for(auto e :edges){
        node[e[0]].push_back(e[1]);
        node[e[1]].push_back(e[0]);
    }
    
    for(int i=0;i<a.size();i++) sum[i]=a[i];
    
    dfs(0);
    if(!sum[0]) return ans;
    else return -1;
}