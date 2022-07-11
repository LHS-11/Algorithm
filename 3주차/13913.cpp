#include<bits/stdc++.h>
using namespace std;
int n,k;
int vis[200001];
int route[200001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> k;
	
	queue<int> q;
	memset(vis,-1,sizeof(vis));
	memset(route,-1,sizeof(route));
	vis[n]=0;
	q.push(n);
	while(!q.empty()){
		auto cur=q.front();
		q.pop();
		if(cur==k){
			break;
		}
		for(int nx:{cur*2,cur+1,cur-1}){
			if(nx<0 || nx>200000) continue;
			if(vis[nx]<0){
				vis[nx]=vis[cur]+1;
				route[nx]=cur;
				q.push(nx);
			}
		}
		
	}
	cout<<vis[k]<<'\n';
	int now=k;
	vector<int>ans;
	while(now!=-1){
		ans.push_back(now);
		now=route[now];
	}
	reverse(ans.begin(),ans.end());
	for(auto c : ans) cout<<c<<' ';
}
