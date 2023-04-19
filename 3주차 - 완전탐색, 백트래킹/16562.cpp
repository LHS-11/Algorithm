#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int>> cost;
int cost1[10004];
int parent[10004],r[10004];
int find(int x){
	if(parent[x]==x) return x;
	return parent[x]=find(parent[x]);
}
void merge(int x,int y){ // 무조건 x 가 작은것 y가 큰 것 
	x=find(x);
	y=find(y);
	
	if(x==y) return;
	
	if(r[x] > r[y]) swap(x,y);
	parent[x]=y;
	if(r[x]==r[y]) r[y]++;
}
void merge1(int x,int y){
	x=find(x);
	y=find(y);
	
	if(x==y) return;
	
	if(cost1[x]<cost1[y]) swap(x,y); // 무조건 비용이 작은 값이 루트 노드로 가도록  
	parent[x]=y;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i=1;i<=n;i++){
		int x; 
		cin >> x;
		cost1[i]=x;
		cost.push_back({x,i});
		parent[i]=i;
		r[i]=1;
		
	}
	parent[0]=0;
	r[0]=1;
	int jun=0;

	sort(cost.begin(),cost.end());
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a>>b;
		merge1(a,b); 
	}
	
	int ans=0;
//	for(int i=0;i<cost.size();i++){
//		int v=cost[i].first;
//		int idx=cost[i].second;
//		if(find(0)!=find(idx)){
//			ans+=v;
//			merge(0,idx);
//		}
//	}
	for(int i=1;i<=n;i++){
		int root=find(i);
		if(find(0)!=root){
			ans+=cost1[root];
			merge1(0,root);
		}
	}

	if(ans>k) cout<<"Oh no";
	else cout<<ans;
	
}
