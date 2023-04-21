#include<bits/stdc++.h>
using namespace std;
int g,p;
vector<int> parent;
int find(int x){
	if(parent[x]==x) return x;
	
	return parent[x]=find(parent[x]);
	
	/*
	parent 1 2 3
	       1 1 2
	
	parent[3]=find(2)=1;
	parent[2]=1;      
	
	*/
}
void merge(int a,int b){
	a=find(a);
	b=find(b);
	
	if(a==b) return;
	
	parent[a]=b;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> g >> p;
	
	parent.resize(g+1);
	
	for(int i=0;i<=g;i++) parent[i]=i;
	
	int ans=0;
	/*
	먼저 gi에서 find를 헀을 때, 값이 0이 아니라면 gi-1과 집합을 만듦
	값이 0이라면 이미 게이트가 다 차지한 것이기 때문에 탈출 
	유니온 파인드를 정확히 이해해야지 풀 수 있는 문제..   
	*/
	for(int i=0;i<p;i++){
		int x;
		cin >> x;
		
		int k=find(x);
		if(k){
			merge(k,k-1);
			ans++;	
		}else break;
	}
	cout<<ans;
}
