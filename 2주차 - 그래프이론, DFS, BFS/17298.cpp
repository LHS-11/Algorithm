#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n;
int mx[1000001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		v.push_back(x);
		mx[i]=v[i];
	}
	
	for(int i=v.size()-1;i>=0;i--){
		// mx[3]=max(mx[4],v[3])
		// mx[2]=max(mx[3],v[2])
		mx[i]=max(mx[i+1],v[i]);
	}
	
	
	for(int i=0;i<v.size();i++){
		if(v[i]>=mx[i+1]) cout<<-1<<' ';
		else{
			int j=i+1;
			while(v[i]>=v[j]){
				j++;
			}
			cout<<v[j]<<' ';
		}
	}
	
}
