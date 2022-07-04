#include<bits/stdc++.h>
using namespace std;
int n;
stack<char> stk;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n;
	
	while(n--){
		int flag=0;
		string s;
		cin >> s;
		for(auto c : s){
			if(c=='(') stk.push(c);
			else {
				if(stk.empty()){
					flag=1;
				}
				else stk.pop();
			}
		}
		if(stk.empty() && !flag) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
		
		while(!stk.empty()) stk.pop();
	}
	
}
