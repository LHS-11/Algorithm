#include<bits/stdc++.h>
using namespace std;
/*
하나의 정점에서 출발해서 깊이가 총 4개이상이면 1이고, 아니면 0  
*/
int n,m,vis[2004];
vector<int> node[2004];
bool flag=false;
bool go(int now,int depth){
	if(depth==4){
		return true;
	}
	
	if(flag) return flag; // 이렇게 안할려면 flag |= go(nxt,depth+1)  
	
	
	flag=false;
	for(int i=0;i<node[now].size();i++){
		int nxt=node[now][i];
		if(vis[nxt]) continue;
		vis[nxt]=1;
		flag=go(nxt,depth+1);
		vis[nxt]=0;
	}
	return flag;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b;

		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	
	
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		if(go(i,0)){
			cout<<1;
			return 0;
		}
		vis[i]=0;
	}
	
	cout<<0;
	return 0;
} 
