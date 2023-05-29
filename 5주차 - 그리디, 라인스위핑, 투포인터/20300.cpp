#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n ;
	
	vector<long long>v(n);
	
	for(int i=0;i<n;i++) cin >> v[i];
	
	sort(v.begin(),v.end());
	
	long long ans=0;
	
	if(n%2==0){ // 짝수일 때
		for(int i=0;i<n/2;i++){
			ans=max(ans,v[i]+v[n-i-1]);
		}
	}else{ // 홀수일 때  
		ans=max(ans,v[n-1]);
		for(int i=0;i<(n-1)/2;i++){
			ans=max(ans,v[i]+v[n-i-2]);
		}
	}
	
	cout<<ans;
} 
