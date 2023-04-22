#include<bits/stdc++.h>
using namespace std;
int t;
vector<int>parent;
vector<tuple<int,int,int>> v;
int check[3004];
set<int> s;
int find(int x){
	if(parent[x]==x) return x;
	return parent[x]=find(parent[x]);
} 
void merge(int a,int b){
	a=find(a);
	b=find(b);
	
	if(a==b) return;
	
	if(a<b) swap(a,b);
	
	parent[a]=b; // 작은쪽이 부모가 되도록 설정  
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
        
		s.clear();
		parent.clear();
		parent.resize(n+1);
		v.clear();
		memset(check,0,sizeof(check));
		
		for(int i=0;i<=n;i++) parent[i]=i;
		
		for(int i=0;i<n;i++){
			int x,y,r;
			cin >> x >> y >> r;
			
			v.push_back(make_tuple(x,y,r));
		}
		
		for(int i=0;i<n;i++){
			int x,y,r;
			tie(x,y,r)=v[i];
			for(int j=i+1;j<n;j++){
				int x1,y1,r1;
				tie(x1,y1,r1)=v[j];
				
				double dis=sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
				
				if(dis<=r+r1){
					merge(i,j);
				}
			}
		}
		
		int ans=0;
		for(int i=0;i<v.size();i++){
			//if(!check[find(i)]){
			//	check[find(i)]=1;
			//	ans++;
			//}
            s.insert(find(i));
		}
		
		cout<<s.size()<<'\n';
	    
	}
}
