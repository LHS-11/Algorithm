#include<bits/stdc++.h>
using namespace std;
int n,m,h,w,sr,sc,fr,fc,ans=-1;
int board[1004][1004],vis[1004][1004];
/*
시작점에서 
h -> y, w -> x 
r -> y , c -> x

sr ~ sr + h 
sc ~ sc + w 
=> 여기 사이에 1이 존재하면 안됨 (끝만 확인하면 됨, 어차피 1씩 이동하기 때문에) 
 
*/
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>> board[i][j];
		}
	}
	cin >> h >> w >> sr>>sc >> fr >> fc ;
	
	queue<tuple<int,int,int>>q;
	q.push(make_tuple(sr,sc,0));
	vis[sr][sc]=1;
	
	while(q.size()){
		int x,y,cnt;
		tie(y,x,cnt)=q.front();
		q.pop();
		
		if(y==fr && x==fc){
			ans=cnt;
			break;
		}
		
		int ex=x+w-1;
		int ey=y+h-1;
		
		for(int i=0;i<4;i++){
			int nex=ex+dx[i]; // 끝점 이동  
			int ney=ey+dy[i];
			int flag=0;
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(i==0){ // 왼쪽 이동  -> 왼쪽 직사각형 라인 확인 
				
				if(nx<=0) continue;
				for(int j=ny;j<ny+h;j++){
					if(j>n || board[j][nx]==1){
						flag=1;
						break;
					}
					
				}
				 
				
			}else if(i==1){ // 위쪽 이동  
				
				if(ny<=0) continue;
				for(int j=nx;j<nx+w;j++) {
					if(j>m || board[ny][j]==1){
						flag=1;
						break;
					}
				}
				
			}else if(i==2){ // 오른쪽 이동 
				if(nex>m) continue;
				for(int j=ney;j>ney-h;j--){
					
					if(j>n || board[j][nex]==1){
						flag=1;
						break;
					}
				}
			}else{ // 아래쪽 이동  
				if(ney>n) continue;
				for(int j=nex;j>nex-w;j--){
					
					if(j>m || board[ney][j]==1){
						flag=1;
						break;
					}
				}
			}
			
			if(!flag && !vis[ny][nx]){
				vis[ny][nx]=1;
				q.push(make_tuple(ny,nx,cnt+1));
			}
		}
	}
	 
	cout<<ans;
}
