// 짝짓기 문제는 stack 생각, 내 원래 풀이보다 깔끔한 풀이 ( stack에 그냥 index를 넣어서 풀면 pair를 써서 할 필요가 없음) 
#include<bits/stdc++.h>
using namespace std;
int ans[1000001];
int arr[1000001];
stack<int> stk;
int n;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	
	//fill(ans,ans+1000000,-1);
	fill(&ans[0],&ans[0]+1000000,-1);
	//memset(ans,-1,sizeof(ans));
	
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		arr[i]=x;
		
		while(!stk.empty() && arr[stk.top()]<x){
			ans[stk.top()]=x;
			stk.pop();
		}
		stk.push(i);
	}
	for(int i=0;i<n;i++) cout<<ans[i]<<' ';
	
} 
