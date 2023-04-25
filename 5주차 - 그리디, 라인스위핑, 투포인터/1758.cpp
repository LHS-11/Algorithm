#include<bits/stdc++.h>
using namespace std; 
/*
어차피 등수에 따라서 마이너스는 고정된 값임
최대한 음수를 안만들어서 돈을 받을 수 있도록 하는게 최대값
그러기 위해서는 정렬 후 작은 값부터 등수를 앞에다가 세우면 되는줄 알았지만..
작은 값들이 앞에서 음수가 되고, 큰 값들도 등수가 미뤄져서 음수가 될 수도 있기 때문에
내림차순, 오름차순으로 정렬해서 비교해야함  
*/
int main(){
	
	int n;
	cin >> n;
	
	vector<int> v(n); 
	
	for(int i=0;i<n;i++) cin>> v[i];
	
	sort(v.begin(),v.end());
	
	int ans=0;
	for(int i=0;i<v.size();i++){
		int value=v[i]-i;
		if(value>0) ans+=value; 
	}
	
	sort(v.begin(),v.end(),greater<int>());
	int ans1=0;
	for(int i=0;i<v.size();i++){
		int value=v[i]-i;
		if(value>0) ans1+=value;
	}
	cout<<max(ans,ans1);
	
}
