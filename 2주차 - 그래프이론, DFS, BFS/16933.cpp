#include<bits/stdc++.h>
using namespace std;
/*
벽 부수고 이동하기 3
이번 문제에서는 낮과 밤이 번갈아가면서 등장한다. 가장 처음에 이동할 때는 낮이고, 
한 번 이동할 때마다 낮과 밤이 바뀌게 된다. 
이동하지 않고 같은 칸에 머무르는 경우에도 낮과 밤이 바뀌게 된다.

만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 
벽을 K개 까지 부수고 이동하여도 된다. 단, 벽은 낮에만 부술 수 있다. 

int vis[y좌표][x좌표][밤/낮][부실 수 있는 벽의 갯수] 
*/ 
int n,m,k,vis[1004][1004][2][14]; // 0 낮, 1 밤  
string s[1004];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i=0;i<n;i++) cin >> s[i];
	
	queue<tuple<int,int,int,int,int>> q;
	q.push(make_tuple(0,0,0,k,1));
	vis[0][0][0][k]=1;
	
	int ans=-1;
	while(q.size()){
		int x,y,flag,chk,cnt;
		tie(y,x,flag,chk,cnt)=q.front();
		q.pop();
		int nflag=(flag+1)%2;
		
		if(y==n-1 && x==m-1){
			ans=cnt;
			break;
		}
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
			
			if(s[ny][nx]=='1' && flag==0 && chk>=1 && !vis[ny][nx][nflag][chk-1]){ // 낮에만 벽 부수기 가능  
				vis[ny][nx][nflag][chk-1]=1;
				q.push(make_tuple(ny,nx,nflag,chk-1,cnt+1));
			}else if(s[ny][nx]=='0' && !vis[ny][nx][nflag][chk]){ // 그냥 이동 할 때  
				vis[ny][nx][nflag][chk]=1;
				q.push(make_tuple(ny,nx,nflag,chk,cnt+1));
			}else if(!vis[y][x][nflag][chk]){ // 가만히 있을 때 ( 밤, 낮 바뀌길 ) 
				vis[y][x][nflag][chk]=1;
				q.push(make_tuple(y,x,nflag,chk,cnt+1));
			}
			
		}
	}
	
	cout<<ans;
}
