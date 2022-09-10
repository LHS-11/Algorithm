#include<bits/stdc++.h>
using namespace std;
int n;
int root;
vector<int> node[51];
int vis[51];
int leaf;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	
	for(int i=0;i<n;i++){ 
		int x;
		cin >> x;
		
		if(x!=-1) {
			node[x].push_back(i);
		}else{
			root=i;
		}
	}
	
	int delNode;
	cin >> delNode;
	
	queue<int> q;
	q.push(root);
	vis[root]=1;
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		if(cur==delNode) break;
		if(node[cur].size()==0){
			leaf++;
		}
		for(int i=0;i<node[cur].size();i++){
			int nxt=node[cur][i];
			if(node[cur].size()==1 && nxt==delNode) leaf++;
			if(vis[nxt] || nxt==delNode) continue;
			vis[nxt]=1;
			q.push(nxt);
		}
		
	}

	cout<<leaf;
	
}
