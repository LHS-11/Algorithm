#include<bits/stdc++.h>
using namespace std;
int n,m,vis[1004][1004],parent[1004],cntt[1004][1004],area[1004][1004]; 
string s[1004];
int ans[1004][1004];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

/*

각 영역마다 카운팅을 미리 해두고,  
*/
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++) cin >> s[i];
	
	int t=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='0' && !cntt[i][j]){
				
				
				queue<pair<int,int>> q;
				q.push(make_pair(i,j));
				vis[i][j]=1;
				int cnt=0;
				
				vector<pair<int,int>> v;
				while(q.size()){
					auto cur=q.front();
					q.pop();
					
					v.push_back(make_pair(cur.first,cur.second));
					cnt++;
					for(int i=0;i<4;i++){
						int nx=cur.second+dx[i];
						int ny=cur.first+dy[i];
					
						if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
						if(vis[ny][nx]) continue;
						
						if(s[ny][nx]=='0'){
							vis[ny][nx]=1;
							q.push(make_pair(ny,nx));
						}
						
					}	
				}
				
				area[i][j]=t;
				cntt[i][j]=cnt;
				for(auto& c : v){
					int y=c.first;
					int x=c.second;
					area[y][x]=t;
					cntt[y][x]=cnt;
				}

				t++;
			}
			
		}
	}
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='1'){
				set<int> st;
				int cnt=1;

				for(int k=0;k<4;k++){
					int nx=j+dx[k];
					int ny=i+dy[k];
					
					if(nx<0 || ny<0 || nx>=m || ny>=n) continue;

					if(st.find(area[ny][nx])==st.end()){
						cnt+=cntt[ny][nx];

						st.insert(area[ny][nx]);
					}
					
				}
				ans[i][j]=cnt%10;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
}
