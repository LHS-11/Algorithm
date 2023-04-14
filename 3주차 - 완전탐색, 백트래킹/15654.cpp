#include<bits/stdc++.h>
using namespace std;
int n,m,vis[9];
vector<int> v;
vector<int> arr;
void go(){
	if(v.size()==m){
		for(auto x :v) cout<<x<<' ';
		cout<<'\n';
		return;
	}
	
	for(int i=0 ;i<n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		v.push_back(arr[i]);
		go();
		v.pop_back();
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>> n >> m;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(),arr.end());
	go();
} 
