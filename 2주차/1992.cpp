#include<bits/stdc++.h>
using namespace std;
int n;
string s[65];
void func(int n, int a,int b){ // a 세로 ,b 가로 
	
	char c=s[a][b];
	
	for(int i=a;i<n+a;i++){
		for(int j=b;j<n+b;j++){
			if(c!=s[i][j]){
				cout<<"(";
				func(n/2,a,b);
				func(n/2,a,b+n/2);
				func(n/2,a+n/2,b);
				func(n/2,a+n/2,b+n/2);
				cout<<")";
				return;
			}
		}
	}
	cout<<c;
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> s[i];
	
	func(n,0,0);
}
