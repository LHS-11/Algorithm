#include<bits/stdc++.h>
using namespace std;
/*
1 2 3 
3 1 2 

1 2 3 4 5
3 1 1 5 5

결국에 처음 노드부터 시작 했을 때, 다시 처음 노드로 돌아와야 함  

*/
int n,vis[104],chk[104];
vector<int> v[104];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n;
		
	for(int i=1;i<=n;i++) {
		int x;
		cin >> x;
		v[i].push_back(x);
	}
	
	for(int i=1;i<=n;i++){
		
		memset(vis,0,sizeof(vis));
		queue<int> q;
		q.push(i);
		vis[i]=1;
		int st=i;
		int en;
		while(q.size()){
			auto cur=q.front();
			q.pop();
			en=cur;
		
			int nxt=v[cur][0];
			if(!vis[nxt]){
				vis[nxt]=1;
				q.push(nxt);
			}
		}
		
		if(st==v[en][0]){
			for(int i=1;i<=n;i++){
				if(!chk[i] && vis[i]){
					chk[i]=1;
				}
			}
		}
	}
	
	vector<int> ans;
	for(int i=1;i<=n;i++){
		if(chk[i]) ans.push_back(i);
	}
	
	cout<<ans.size()<<'\n';
	sort(ans.begin(),ans.end());
	
	for(auto& a : ans) cout<<a<<'\n';
}