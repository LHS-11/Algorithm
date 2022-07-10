#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int vis[51][51];
int n,m;// 세로,가로
string s[51];
int ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n>>m;
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='L'){
				int dis=0;
				fill(&vis[0][0],&vis[0][0]+51*51,-1);
				queue<pair<int,int>>q;
				q.push({i,j});
				vis[i][j]=0;
				while(!q.empty()){
					auto cur =q.front();
					q.pop();
					dis=max(dis,vis[cur.first][cur.second]);
					for(int i=0;i<4;i++){
						int nx=cur.second+dx[i];
						int ny=cur.first+dy[i];
						if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
						if(vis[ny][nx]<0 && s[ny][nx]=='L'){
							vis[ny][nx]=vis[cur.first][cur.second]+1;
							q.push({ny,nx});
						}
					}
				} 	
				ans=max(dis,ans);
			}
			
		}
	}
	cout<<ans;
}
