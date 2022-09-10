#include<bits/stdc++.h>
using namespace std;
int n,k;
int vis[200001];
int cnt[200001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> k;
	
	queue<int> q;
	memset(vis,-1,sizeof(vis));
	vis[n]=0;
	cnt[n]=1;
	q.push(n);
	while(!q.empty()){
		auto cur=q.front();
		q.pop();
		for(int nx:{cur*2,cur+1,cur-1}){
			if(nx<0 || nx>200000) continue;
			if(vis[nx]<0){
				vis[nx]=vis[cur]+1;
				cnt[nx]+=cnt[cur];
				q.push(nx);
			}else if(vis[nx]==vis[cur]+1) cnt[nx]+=cnt[cur];
		}
		
	}
	cout<<vis[k]<<'\n'<<cnt[k];
}
