#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int l=1e9+4,r;
vector<pair<int,int>> v[10004];
int vis[10004];
bool go(int cost){
	
	queue<int> q;
	q.push(x);
	vis[x]=1;
	while(q.size()){
		auto cur=q.front();
		q.pop();
		
		if(cur==y) return false;
		
		for(int i=0;i<v[cur].size();i++){
			int nxt=v[cur][i].first;
			
			if(!vis[nxt] && v[cur][i].second>=cost){
				q.push(nxt);
				vis[nxt]=1;
			}
		}
	}
//	cout<<cost<<endl;
	return true;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a>> b >> c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
		l=min(c,l);
		r=max(c,r);
	}
	
	cin >> x >>y;
	
	int ans=0;
	while(l<=r){ // 최대 중량을 기준으로 파라메트릭 서치 (근데 BFS를 곁들인... )
		int m=(l+r)>>1;
		
		if(go(m)){
			r=m-1;
		}else {
			l=m+1;
			ans=m;
		}
		
		memset(vis,0,sizeof(vis));
	}
	
	cout<<ans;
}
