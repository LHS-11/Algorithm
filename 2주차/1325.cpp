#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> node[10001];
vector<int> ans[10004];
int vis[10001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	
	while(m--){
		int a,b;
		cin >> a>>b;
		node[b].push_back(a);
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		queue<int> q;
		q.push(i);
		vis[i]=1;
		while(!q.empty()){
			auto cur=q.front();
			q.pop();
			
			for(int i=0;i<node[cur].size();i++){
				int nxt=node[cur][i];
				if(!vis[nxt]){
					q.push(nxt);
					vis[nxt]=1;
					cnt++;
				}
			}
		}
		memset(vis,0,sizeof(vis));
		mx=max(mx,cnt);
		ans[cnt].push_back(i);
	}
	
	for(int i=0;i<ans[mx].size();i++){
		cout<<ans[mx][i]<<' ';
	}
}
