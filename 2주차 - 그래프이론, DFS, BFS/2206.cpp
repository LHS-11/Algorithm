#include<bits/stdc++.h>
using namespace std;
/*
벽 부수고 이동하기 1
=> 벽을 최대 1개까지 부셔서, 도착할 수 있는 최단 경로를 구하는 프로그램을 작성하시오.  
BFS를 돌려서 구하는데, 상태를 추가해서 실행 ( O(N*M) ) 
*/
int n,m;
string s[1004];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int vis[1004][1004][2];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++) cin >> s[i];
	
	queue<tuple<int,int,int,int>> q; // y 좌표, x 좌표, 부수기 스킬 사용 가능한지, 경로  
	q.push(make_tuple( 0,0,0,1)) ;
	vis[0][0][0]=1;
	
	
	int ans=-1;
	
	while(q.size()){
		auto cur=q.front();
		q.pop();
		
		if(get<0>(cur)==n-1 && get<1>(cur)==m-1){
			ans=get<3>(cur);
			break;
		} 
		
		for(int i=0;i<4;i++){
			int nx=get<1>(cur)+dx[i];
			int ny=get<0>(cur)+dy[i];
			int chk=get<2>(cur);
			int cnt=get<3>(cur); 
			
			if(nx<0 || ny<0 || nx>= m  || ny>= n) continue;
			
//			if(vis[ny][nx][chk]) continue;
			
			if(s[ny][nx]=='1' && chk !=1  && !vis[ny][nx][1]){ // 다음 도착하는 곳이 벽이고 아직 벽을 부실 수 있을 때, 
				vis[ny][nx][1]=1;
				q.push(make_tuple(ny,nx,1,cnt+1));
			}else if(s[ny][nx]=='0' && !vis[ny][nx][chk] ){ // 다음, 도착하는 곳이 벽이 아닐 때,  
				vis[ny][nx][chk]=1;
				q.push(make_tuple(ny,nx,chk,cnt+1));
			}
			
		}
	}
	
	
	cout<<ans;
	
}
