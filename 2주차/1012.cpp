#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
queue<pair<int,int > > q;
int t;
int arr[51][51];
int vis[51][51];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> t;
	
	while(t--){
		memset(vis,0,sizeof(vis));
		int n,m,k;
		cin >> m >> n>>k ;// 가로, 세로, 배추  
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				arr[i][j]=0;
			}
		}
		
		while(k--){
			int a,b;
			cin >> a >> b;
			arr[b][a]=1;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]==1 && !vis[i][j]){
					vis[i][j]=1;
					q.push({i,j});
					ans++;
					while(!q.empty()){
						auto cur =q.front();
						q.pop();
						
						for(int i=0;i<4;i++){
							int nx=cur.second+dx[i];
							int ny=cur.first+dy[i];
							
							if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
							
							if(!vis[ny][nx]&& arr[ny][nx]==1){
								vis[ny][nx]=1;
								q.push({ny,nx});
							} 
						}
					}	
				}
			}
		}
		
		cout<<ans<<'\n';
		 
	}
}
