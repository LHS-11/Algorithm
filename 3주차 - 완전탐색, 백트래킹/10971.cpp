#include<bits/stdc++.h>
using namespace std;
int dis[14][14];
int n,vis[14];
int ans=INT_MAX;
void go(int now,int nxt,int cnt,int sum){
	
	if(cnt==n&& now==nxt) {
		ans=min(ans,sum);
		return;
	}
		
	
	for(int i=0;i<n;i++){
		if(vis[i] || !dis[now][i]) continue;
		vis[i]=1;
		go(i,nxt,cnt+1,sum+dis[now][i]);
		vis[i]=0;
		
	}
	return;
}
int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> dis[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		vector<int> v;
		go(i,i,0,0);
		memset(vis,0,sizeof(vis));
	}
	cout<<ans<<endl;
	
}
