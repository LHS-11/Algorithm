#include<bits/stdc++.h>
using namespace std;
int h,w,n,ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> h>> w;
	cin >> n;
	
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i].first >> v[i].second;
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int h1=h,w1=w;
			
			// i가 회전 안 했을 때
			if(h1-v[i].first>=0 && w1-v[i].second>=0){
				int h2=h1-v[i].first;
				int w2=w1-v[i].second;
				
				// 2가지 (h1,w2), (h2,w1)  
				
				// j가 회전 안 했을 때 , j가 회전 했을 때
				if((h1-v[j].first>=0 && w2-v[j].second>=0) || (h1-v[j].second>=0 && w2-v[j].first>=0)
				|| (h2-v[j].first>=0 && w1-v[j].second>=0) || (h2-v[j].second>=0 && w1-v[j].first>=0)){
					ans=max(ans,v[i].first*v[i].second + v[j].first*v[j].second);
				}
			}
			
			if(h1-v[i].second>=0 && w1-v[i].first>=0){ // i가 회전 했을 때 
				int h2=h1-v[i].second;
				int w2=w1-v[i].first;
				
				// 2가지 (h1,w2), (h2,w1)  
				
				// j가 회전 안했을 때 , j가 회전 했을 때
				if((h1-v[j].first>=0 && w2-v[j].second>=0) || (h1-v[j].second>=0 && w2-v[j].first>=0 )
				|| (h2-v[j].first>=0 && w1-v[j].second>=0) || (h2-v[j].second>=0 && w1-v[j].first>=0)){
					ans=max(ans,v[i].first*v[i].second + v[j].first*v[j].second);
				}
			}
			
		}
	}
	cout<<ans;
} 
