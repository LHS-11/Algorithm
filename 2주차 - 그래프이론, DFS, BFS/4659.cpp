#include<bits/stdc++.h>
using namespace std; // a -> 26 , e-> a+4 , i->a+8, o-> i+14 , u->a+20
int chk[26];
string s;
int main(){
	
	cin >> s;
	
	while(s!="end"){
		int flag=0;	
		if(s.find('a')==string::npos && s.find('e')==string::npos && s.find('i')==string::npos && s.find('o')==string::npos && s.find('u')==string::npos ){
		 	flag=1;
				
		}
		int n1=0,n2=0;
		for(auto c : s){
			if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
				n1++;
				n2=0;
			}else{
				n1=0;
				n2++;
			}
			if(n1==3 || n2==3){
				flag=1;
				break;
			}
		}
		int n3=0;
		if(s.size()!=1){
			for(int i=1;i<s.size();i++){
				if(s[i-1]==s[i]){
					if(!(s[i]=='e'||s[i]=='o')){
						flag=1;
						break;
					}
				}
			}
		}
		
		if(flag) cout<<"<"<<s<<">"<<" is "<<"not acceptable.\n";
		else cout<<"<"<<s<<">"<<" is "<<"acceptable.\n";
		
		cin >> s;
	}
}
