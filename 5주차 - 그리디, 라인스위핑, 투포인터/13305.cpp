#include<bits/stdc++.h>
using namespace std;
const int MAX= 1e5+4;
int cost[MAX];
int dis[MAX];
int n;
/*
최대한 기름값이 싼 주유소에서 많이 사서 가면 이득인데, 
 
*/
int main(){
	
	cin >> n;
	for(int i=0;i<n-1;i++) cin >> dis[i];
	for(int i=0;i<n;i++) cin >> cost[i];
	
	long long stCost=cost[0];
	long long stDis=0;
	
	long long ans=0;
	for(int i=1;i<n;i++){
		stDis+=dis[i-1];
		if(cost[i]<=stCost){
			
			ans+=stCost*stDis;
			stDis=0;
			stCost=cost[i];
		}
		
	}
	cout<<stDis<<' '<<stCost;
	if(!stDis) ans+=stCost*stDis;
	
	cout<<ans;
	
}
