#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	while(1){
		stack<char> stk;
		int flag=0;
		string s;
		getline(cin,s);
		if(s==".") break;
		else{
			for(auto c: s){
				if(c=='(' || c=='[') stk.push(c);
				else if(c==')'){
					if(stk.empty() || stk.top()=='['){
						flag=1; break;
					}
					else if(stk.top()=='(' && !stk.empty()) stk.pop();
				}
				else if(c==']'){
					if(stk.empty() || stk.top()=='('){
						flag=1; break;
					}
					else if(stk.top()=='[' && !stk.empty()) stk.pop();
					else {
						flag=1;
						break;
					}
				}
			}
		}
		if(stk.empty() && !flag) cout<<"yes"<<'\n';
		else cout<<"no"<<'\n';
	}
}
