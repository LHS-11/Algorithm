#include<bits/stdc++.h>
using namespace std;
/*
3+9*2
392*+

123*+45/-
(2*3)+1- 4/5
7-0.8=6.2
5
4
3
2
1

-
/
+
*

*/
int n,vis[27];
double num[27];
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> s;
	
	int sz=0;
	for(int i=0;i<s.size();i++){
		if((s[i]>='A' && s[i]<='Z') && !vis[s[i]-'A']) {
			sz++;
			vis[s[i]-'A']=1;
		}
	}
	

	for(int i=0;i<sz;i++) {
		cin >> num[i];
	}
	
	stack<double> number;
	for(int i=0;i<s.size();i++){
		if(s[i]>='A' && s[i]<='Z'){
			number.push(num[s[i]-'A']);
		}else{
			double a=number.top(); number.pop();
			double b=number.top(); number.pop();
			double c;
			if(s[i]=='-'){
				c=b-a;
			}else if(s[i]=='+'){
				c=a+b;
			}else if(s[i]=='/'){
				c=b/a;
			}else{
				c=a*b;
			}
			number.push(c);
		}
	}
	
	cout<<fixed;
	cout.precision(3);
	cout<<number.top();
	
	
	
}
