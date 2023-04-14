#include<bits/stdc++.h>
using namespace std;
int n,m,vis[9];
vector<int> v;
void go(){
	if(v.size()==m){
		for(auto x :v) cout<<x<<' ';
		cout<<'\n';
		return;
	}
	
	for(int i=1;i<=n;i++){
		v.push_back(i);
		go();
		v.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>> n >> m;
	go();
} 
