#include<bits/stdc++.h>
using namespace std;
int n,m,vis[9];
vector<int> v;
vector<int> arr;
void go(int idx){
	if(v.size()==m){
		for(auto x :v) cout<<x<<' ';
		cout<<'\n';
		return;
	}
	
	for(int i=idx;i<n;i++){
		v.push_back(arr[i]);
		go(i);
		v.pop_back();
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
	go(0);
} 
