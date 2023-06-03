#include<bits/stdc++.h>
using namespace std;

//그래프 탐색인데, 명검을 먹으면 벽을 다부실 수 있음 이걸 구분해서 최단거리탐색 
 
const int INF=987654321;
int n,m,t,ans1=INF,ans2=INF;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int board[104][104];
int vis[104][104];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);

	cin >>n>>m>>t;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>board[i][j];
		}
	}
	
	
	// 먼저 명검을 안먹고 공주를 구할 수 있는지 확인  
	
	queue<tuple<int,int,int>>q;
	q.push(make_tuple(0,0,0));
	vis[0][0]=1;
	while(q.size()){
		int x,y,cnt;
		tie(y,x,cnt)=q.front();
		q.pop();
		
		if(x==m-1 && y==n-1){
			ans1=cnt;
			break;
		}
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
			
			if(board[ny][nx]!=1 && !vis[ny][nx]){
				vis[ny][nx]=1;
				q.push(make_tuple(ny,nx,cnt+1));
			}
		}
	}
	
	while(q.size()) q.pop();
	// 명검을 먹고, 공주를 구하기  
	
	memset(vis,0,sizeof(vis));
	q.push(make_tuple(0,0,0));
	int sx,sy;
	while(q.size()){
		int x,y,cnt;
		tie(y,x,cnt)=q.front();
		q.pop();
		
		if(board[y][x]==2){
			ans2=cnt;
			sx=x; sy=y;
			break;
		}
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
			
			if(board[ny][nx]!=1 && !vis[ny][nx]){
				vis[ny][nx]=1;
				q.push(make_tuple(ny,nx,cnt+1));
			}
		}
	}
	
	
	if(ans2!=INF){
		while(q.size()) q.pop();
		memset(vis,0,sizeof(vis));
		q.push(make_tuple(sy,sx,ans2));
		while(q.size()){
			int x,y,cnt;
			tie(y,x,cnt)=q.front();
			q.pop();
			
			if(x==m-1 && y==n-1){
				ans2=cnt;
				break;
			}
			
			for(int i=0;i<4;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				
				if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
				
				if(!vis[ny][nx]){
					vis[ny][nx]=1;
					q.push(make_tuple(ny,nx,cnt+1));
				}
			}
		}
	}
	
	cout<<ans1<<' '<<ans2<<endl;
	
	ans1=min(ans1,ans2);

	if(ans1<=t) cout<<ans1;
	else cout<<"Fail";
	
	
} 

