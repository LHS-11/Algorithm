#include<bits/stdc++.h>
using namespace std;
int r,c,n;
string s[204];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int tt[204][204];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> r >> c >> n;
	
	for(int i=0;i<r;i++){
		cin>> s[i];
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]=='O'){
				tt[i][j]=0;
			}
		}
	}
	
	for(int t=2;t<=n;t++){
		
		if(t%2==0){
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(s[i][j]=='.'){
						s[i][j]='O';
						tt[i][j]=t;						
					}

				}
			}
		}else{
			queue<pair<int,int>>q;
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(s[i][j]=='O' && tt[i][j]+3==t){
						q.push({i,j});
					}
				}
			}
			
			while(q.size()){
				auto cur=q.front();
				q.pop();
				s[cur.first][cur.second]='.';
				tt[cur.first][cur.second]=0;
				for(int i=0;i<4;i++){
					int nx=cur.second+dx[i];
					int ny=cur.first+dy[i];
								
					if(nx<0 || ny<0|| nx>=c || ny>=r) continue;
						
					s[ny][nx]='.';
					tt[ny][nx]=0;
				}
			}
				
		}
	}
	
	for(int i=0;i<r;i++){
		cout<<s[i]<<'\n';
	}
	
}
