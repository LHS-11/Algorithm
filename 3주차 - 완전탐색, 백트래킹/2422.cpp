#include<bits/stdc++.h>
using namespace std;
int n,m,vis[204],ans,t[204][204];
vector<int> v;
vector<int> chk[204];
void go(int idx,int k){
	if(k==3){
		
		int flag=0;
		for(int i=0;i<v.size();i++){
			
			for(int j=0;j<chk[v[i]].size();j++){
				int x=chk[v[i]][j];
				
				for(int k=i+1;k<v.size();k++){
					if(x==v[k]){
						flag=1;
						break;
					}
				}
				if(flag) break;
					
			}
			if(flag) break;
		}
		if(flag) return;
		
		ans++;
		return;
	}
	
	for(int i=idx;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		v.push_back(i);
		go(i+1,k+1);
		v.pop_back();
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	/*
	모든 조합을 구하고, 안되는 조합을 제거  
	*/
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		chk[a].push_back(b);
		chk[b].push_back(a);
		t[a][b]=1;
		t[b][a]=1;
	}
	
//	go(1,0);
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(t[i][j]) continue;
			for(int k=j+1;k<=n;k++){
				if(t[j][k]) continue;
				ans++;
				cout<<i <<' '<<j<<' '<<k<<endl;
			}
		}
	}
	
	cout<<ans;
}
