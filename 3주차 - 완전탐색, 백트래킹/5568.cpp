#include<bits/stdc++.h>
using namespace std;
int n,k,vis[14],ans;
map<string,int> mp;
vector<int> v,vt;
void dfs(int idx,int sz){
	
	if(sz==k){
		vector<int> vtt=vt;
		sort(vtt.begin(),vtt.end());
		
		do{
			string str="";
			for(auto & c : vtt) str+=to_string(c); 
			
			if(!mp[str]){
				mp[str]=1;
				ans++;
			}
			
		}while(next_permutation(vtt.begin(),vtt.end()));
		
		return;
	}
	
	for(int i=idx;i<n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		vt.push_back(v[i]);
		dfs(i,sz+1);
		vt.pop_back();
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> k;
	
	v.resize(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	
	dfs(0,0);
	
	cout<<ans;
	
	
}
