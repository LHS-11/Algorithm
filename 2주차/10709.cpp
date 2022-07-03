#include<bits/stdc++.h>
using namespace std;
int h,w; // 세로 , 가로
string s[101];
int vis[101][101];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	 cin >> h>> w;
	 
	 queue<pair<int,int>> q;
	 
	 for(int i=0;i<h;i++) {
	 	cin >> s[i];
	 	for(int j=0;j<w;j++)
			if(s[i][j]=='c') {
				vis[i][j]=1;
				q.push({i,j});	
			}	
	 }
	 
	 while(!q.empty()){
	 	auto cur =q.front();
	 	q.pop();
	 	
	 	int nx=cur.second+1;
		int ny=cur.first;
	 	
		if(nx<0 || nx>=w) continue;
		
		if(!vis[ny][nx] && s[ny][nx]=='.'){
			vis[ny][nx]=vis[cur.first][cur.second]+1;
			q.push({ny,nx});	
		}
	 }
	 
	 for(int i=0;i<h;i++){
	 	for(int j=0;j<w;j++){
	 		cout<<vis[i][j]-1<<' ';
		 }
		 cout<<'\n';
	 }
	 
} 
