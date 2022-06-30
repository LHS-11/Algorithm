#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	while(cin>>n){
		int num;
		long long ll;
		string s="1";
		
		cin >> num;
		
		while(1){
			if(stoll(s)%num==0){
				break;
			}else{
				s+='1';
			}
		}
		cout<<s.size()<<'\n';
	}
}
