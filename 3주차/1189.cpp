#include<bits/stdc++.h>
using namespace std;
int r,c,k;
int vis[6][6];
string s[6];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ans;
int dfs(int y,int x,int n){
	if(y==0 && x==c-1 && n==k){
		return 1; 
	}
	cout<<y<<' '<<x << ' '<<n<<endl;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx<0 || nx>=c || ny<0 || ny>=r) continue;
		
		if(s[ny][nx]=='.'){
			vis[ny][nx]=1;
			ans+=dfs(ny,nx,n+1);
			vis[ny][nx]=0;
		}
		
		
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	 
	cin >> r >>c >>k;
	
	for(int i=0;i<r;i++) cin >> s[i];
	
	vis[r-1][0]=1;
	cout<<dfs(r-1,0,1);
}
