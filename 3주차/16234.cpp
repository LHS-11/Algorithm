#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int n,l,r;
int vis[51][51];
int ans;
int a[51][51];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>> n >> l >> r;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >>a[i][j]; 
		}
	}

	while(1){
		int flag=0;
		int cnt,sum;
		fill(&vis[0][0],&vis[0][0]+51*51,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(vis[i][j]) continue;
				cnt=0;
				sum=0;
				vector<pair<int,int>> cty;
				queue<pair<int,int >>q;
				q.push({i,j});
				vis[i][j]=1;
				while(!q.empty()){
					auto cur =q.front();
					q.pop();
					cty.push_back({cur.first,cur.second});
					sum+=a[cur.first][cur.second];
					cnt++;
					for(int i=0;i<4;i++){
						int nx=cur.second+dx[i];
						int ny=cur.first+dy[i];
						if(nx<0 || nx>=n || ny<0 || ny>= n) continue;
						int pp=abs(a[cur.first][cur.second]-a[ny][nx]);
						if(pp>=l && pp<=r && !vis[ny][nx]){
							flag=1;
							q.push({ny,nx});
							vis[ny][nx]=1;
						}
					}
				}
				for(int i=0;i<cty.size();i++){
					a[cty[i].first][cty[i].second]=sum/cnt;
				}		
			}
		}
		if(!flag) break;
		ans++;
	}
	cout<<ans;
}
