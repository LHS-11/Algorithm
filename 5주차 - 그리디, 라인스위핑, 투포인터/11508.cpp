#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	
	sort(v.begin(),v.end(),greater<int>());
	
	int ans=0;
	for(int i=0;i<n;i++){
		if((i+1)%3==0) continue;
		ans+=v[i];
	}
	cout<<ans;
} 
