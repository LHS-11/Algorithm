#include<bits/stdc++.h>
using namespace std;
/*
치킨 중에 3개를 선택하고, 선택한 치킨의 각 유저들의 만족도가 정해지기 때문에
해당 값들을 더해서 최댓값을 구함 
*/
int n,m,ans,vis[34],t[34][34];
vector<int> v,vt;
void go(int idx,int sz){
	if(sz==3){
		
		int sum=0;
		for(int i=0;i<n;i++){
			int mx=0;
			for(auto &e : vt){
				mx=max(mx,t[i][e]);
			}
			sum+=mx;
		}
		ans=max(ans,sum);
		return;
	}
	
	for(int i=idx;i<m;i++){
		if(vis[i]) continue;
		vis[i]=1;
		vt.push_back(i);
		go(i,sz+1);
		vt.pop_back();
		vis[i]=0;
	}
} 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>t[i][j];
		}
	}
	
//	go(0,0);
	
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			for(int k=j+1;k<m;k++){
				
				int sum=0;
				for(int a=0;a<n;a++){
					int mx=0;
					mx=max(mx,t[a][i]);
					mx=max(mx,t[a][j]);
					mx=max(mx,t[a][k]);
					sum+=mx;
				}
				ans=max(ans,sum);
			}
		}
	}
	
	cout<<ans;
}
