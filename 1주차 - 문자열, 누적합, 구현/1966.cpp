#include<bits/stdc++.h>
using namespace std;
int t,mx;
int num[10];
int main(){
	
	cin>>t;
	
	while(t--){
		int n,m;
		
		cin >> n >> m;
		
		queue<pair<int,int>> q;
		priority_queue<int> pq;
		memset(num,0,sizeof(num));
		mx=0; 
		
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			pq.push(x);	
			q.push(make_pair(x,i));
		}
		
		int ans=1;
		while(1){
			auto cur=q.front();
			
			if(pq.top()==cur.first){
				pq.pop();
				if(m==cur.second) break;
				ans++;
			} 
			
			q.pop();
			q.push(cur);
			
		}
		
		cout<<ans<<'\n';
	}
}
