// ¦���� ������ stack ����, �� ���� Ǯ�̺��� ����� Ǯ�� ( stack�� �׳� index�� �־ Ǯ�� pair�� �Ἥ �� �ʿ䰡 ����) 
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
