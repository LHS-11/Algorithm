#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int a[101][101];
int vis[101][101];
int m,n,k;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> m>>n >> k; // 세로, 가로 , 직사각형의 개수
	
	while(k--){
		int x1,y1,x2,y2;
		cin >> x1 >>y1>>x2>>y2;
		
		for(int i=y1;i<y2;i++){
			for(int j=x1;j<x2;j++){
				a[i][j]=1;
			}
		}
	}
	
	vector<int> v;
	int ans=0;
	int cnt;
	queue<pair<int,int>> q;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==0 && !vis[i][j]){
				q.push({i,j});
				vis[i][j]=1;
				ans++;
				cnt=0;
				while(!q.empty()){
					auto cur=q.front();
					q.pop();
					cnt++;
					for(int i=0;i<4;i++){
						int nx=cur.second+dx[i];
						int ny=cur.first+dy[i];
						if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
						
						if(!vis[ny][nx] && a[ny][nx]==0){
							vis[ny][nx]=1;
							q.push({ny,nx});
						}
					}
				}
				v.push_back(cnt);	
			}
		}
	}
	cout<<ans<<endl;
	sort(v.begin(),v.end());
	for(auto c:v) cout<< c<<' ';
}
