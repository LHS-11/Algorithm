#include<bits/stdc++.h>
using namespace std;
int n,m;
int check[504];
vector<int>parent;
int find(int x){
	if(parent[x]==x ) return x;
	
	return parent[x]=find(parent[x]);
}
void merge(int a,int b){
	a=find(a);
	b=find(b);
	
	if(a==b) {
		parent[a]=0;
		return;
	}
	
	if(a<b) swap(a,b);
	
	parent[a]=b; // 작은게 부모가 되도록  
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	int num=1;
	while(1){
		cin >> n >> m;
		
		if(!n && !m) break;
		
		parent.clear();
		parent.resize(n+1);
		memset(check,0,sizeof(check));
		
		for(int i=0;i<=n;i++) parent[i]=i;
		
		for(int i=0;i<m;i++){
			int a,b;
			cin >> a >> b;
			merge(a,b);
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!check[find(i)] && find(i)){
				ans++;
				check[find(i)]=1;
			}
		}
			
		if(!ans) cout<<"Case "<<num<<": No trees.\n"; 
		else if (ans==1) cout<<"Case "<<num<<": There is one tree.\n";
		else cout<<"Case "<<num<<": A forest of "<<ans<<" trees.\n";
		
//		for(int i=1;i<=n;i++){
//			cout<<parent[i]<<' ';
//		}
//		cout<<endl;
		num++;
	}
} 
