#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	
	long long i=0;
	while(1){
		s=to_string(i);
		
		if(s.find("666")!=string::npos){
			n--;
		}
		if(!n) break;
		
		i++;
	}
	cout<<s;
} 
