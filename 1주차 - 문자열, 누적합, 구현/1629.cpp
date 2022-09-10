#include<bits/stdc++.h>
using namespace std;
long long a,b,c,ans;
long long func(long long b){
	if(b==1){
		return a%c;
	}
	if(b%2==0){
		return (func(b/2)*func(b/2))%c;
	}else{
		return (func(b/2)*func(b/2)%c*a)%c;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> a >> b >> c;
	cout<<func(b);
}
