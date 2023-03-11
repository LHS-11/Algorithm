/*
Boj 1449
*/
#include<bits/stdc++.h>
using namespace std;
int N,L;
int main(){
	ios::sync_with_stdio(0) ; cin.tie(0);
	cin >> N >> L;
	vector<double>v(N);
	
	for(int i=0;i<N;i++) {
		cin >> v[i];
	} 
	
	sort(v.begin(),v.end());
	
	int cnt=0;
	for(int i=0;i<v.size();){
		double st=v[i];
		st-=0.5;
		st+=L;
		
		while(i<v.size() && st>=v[i]+0.5){
			i++;
		}
		
		cnt++;
	}
	
	cout<<cnt;
	
}
