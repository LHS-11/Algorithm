/*
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
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, T;
char graph[100][100];
bool visited[100][100][2];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
void bfs() {
	queue<pair<pair<int, int>, pair<bool, int>>> q;
	q.push({ {0,0}, {false,0} });

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		bool sword = q.front().second.first;
		int t = q.front().second.second;

		if (t > T) {
			cout << "Fail";
			return;
		}
		if (r == N - 1 && c == M - 1) {
			cout << t;
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			int nt = t + 1;
			if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
				if (sword) {
					if (!visited[nr][nc][1]) {
						q.push({ { nr,nc }, { true,nt } });
						visited[nr][nc][1] = true;
					}
				}
				else {
					if (graph[nr][nc] == '0'&& !visited[nr][nc][0]) {
						q.push({ {nr,nc}, {false,nt} });
						visited[nr][nc][0] = true;
					}
					else if (graph[nr][nc] == '2' && !visited[nr][nc][0]) {//검 획득
						q.push({ {nr,nc} ,{true,nt} });
						visited[nr][nc][1] = true;
					}
					
				}
			}
		}
	}
	cout << "Fail";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	bfs();
	return 0;
}
