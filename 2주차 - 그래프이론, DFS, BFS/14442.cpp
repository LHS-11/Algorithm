/*
벽 부수고 이동하기 2 
최대 k개의 벽을 부실 수 있음. 
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k,vis[1004][1004][14];
string s[1004];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i=0;i<n;i++) cin >> s[i];
	
	queue<tuple<int,int,int,int>> q;
	vis[0][0][k]=1;
	q.push(make_tuple(0,0,k,1));
	
	int ans=-1;
	while(q.size()){
		int x,y,k,cnt;
		tie(y,x,k,cnt)=q.front();
		q.pop();
		
		if(y==n-1 && x==m-1){
			ans=cnt;
			break;
		}
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0 || ny<0 || nx>= m || ny>=n) continue;
			
			// 아직 부실 수 있는 벽이 남아 있을 때,
			if(s[ny][nx]=='1' && k>=1 && !vis[ny][nx][k-1]){
				vis[ny][nx][k-1]=1;
				q.push(make_tuple(ny,nx,k-1,cnt+1));
				
			}else if(s[ny][nx]=='0' && !vis[ny][nx][k]){
				vis[ny][nx][k]=1;
				q.push(make_tuple(ny,nx,k,cnt+1));
			}
		}
	}
	
	cout<<ans;
	
}
