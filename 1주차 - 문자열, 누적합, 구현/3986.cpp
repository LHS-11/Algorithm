#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n;
	
	while(n--){
		stack<char> stk;
		string s;
		cin >> s;
		for(auto c :s){
			if(stk.empty()) stk.push(c);
			else{
				if(stk.top()==c) stk.pop();
				else stk.push(c);
			}
		}
		if(stk.empty()) cnt++;
	}
	cout<<cnt;
}
