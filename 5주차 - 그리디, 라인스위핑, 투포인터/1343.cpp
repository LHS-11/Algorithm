#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	
	vector<string> v;
	
	string str="";
	for(int i=0;i<s.size();i++){
		if(s[i]=='.'){
			v.push_back(str);
			v.push_back(".");
			str="";
		}else str+=s[i];
	}
	if(str.size()) v.push_back(str);
	
	string ans="";
	int flag=2;
	for(int i=0;i<v.size();i++){
		int sz=v[i].size();
		flag=0;
		int j;
		int a;
		
		if(sz==1 && v[i]==".") {
			ans+=".";
			continue;	
		}
		for(j=sz/4;i>=0;i--){
			
			int k=sz;
			k-=(j*4);
			
			if(k%2==0){
				a=k/2;
				flag=1;
				break;
			}
		}
		if(flag){
			for(int i=0;i<j;i++){
				ans+="AAAA";
			}
			for(int i=0;i<a;i++){
				ans+="BB";
			}
		}else{
			flag=2;
			break;
		}
	}
	if(flag==2) cout<<-1;
	else cout<<ans;
}
