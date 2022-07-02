#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int n;
int mx=0;
int a[101][101];
int vis[101][101];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>> a[i][j];
			if(mx<a[i][j]) mx=a[i][j];
		}
	}
	
	int ans=0,cnt=0;
	for(int i=0;i<=mx;i++){ // 물의 높이가 mn~ mx 사이 
		queue<pair<int,int>>q;
		int board[101][101];
		memset(vis,0,sizeof(vis));
		
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(a[j][k]<=i){
					board[j][k]=0;
				}else board[j][k]=1;
			}
		}
		cnt=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(board[j][k]==1 && !vis[j][k]){
					vis[j][k]=1;
					q.push({j,k});
					cnt++;
					while(!q.empty()){
						auto cur=q.front();
						q.pop();
						for(int i=0;i<4;i++){
							int nx=cur.second+dx[i];
							int ny=cur.first+dy[i];
							if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
							if(!vis[ny][nx] && board[ny][nx]==1){
								q.push({ny,nx});
								vis[ny][nx]=1;
							}
						}
					}		
				}
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	
	
}
