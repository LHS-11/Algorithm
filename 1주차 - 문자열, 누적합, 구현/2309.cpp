#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	for(int i=0;i<9;i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	sort(v.begin(),v.end());
	do{
		int sum=100;
		for(int i=0;i<7;i++){
			sum-=v[i];
		}
		if(sum==0) break;
	}while(next_permutation(v.begin(),v.end()));
	
	for(int i=0;i<7;i++) cout<<v[i]<<'\n';
}
