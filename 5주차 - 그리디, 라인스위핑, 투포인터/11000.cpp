/*
Boj 11000 강의실 배정 
*/
#include<bits/stdc++.h>
using namespace std;
int N;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	vector<pair<int,int>> v(N);
	for(int i=0;i<N;i++){
		int a,b;
		cin >> a>> b;
		v[i]={a,b};
	}
	
	sort(v.begin(),v.end());
	
	int st=v[0].second;
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(st);
	int ans=0;
	
	for(int i=1;i<v.size();i++){
		if(pq.top()<=v[i].first) pq.pop();
		pq.push(v[i].second);
	}
	
	cout<<pq.size();
}
