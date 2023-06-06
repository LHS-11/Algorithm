#include<bits/stdc++.h>
using namespace std;
int n,m,ans,vis[27][27];
void dfs(int x,int y){
	
	if(x>m){
		y+=1;
		x=1;
	}
	
	if(y>n) {
		ans++;
		return;
	}
	
	if(!(vis[y-1][x] && vis[y][x-1] && vis[y-1][x-1])){
		vis[y][x]=1;
		dfs(x+1,y);
		vis[y][x]=0;
	}
	dfs(x+1,y);
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		
	}
	
	dfs(1,1);
	
	cout<<ans;
}
