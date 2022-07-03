#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> t;
	
	while(t--){
		int n; int sum=0; 
		cin >> n;
		
		if(n>=5){
			for(int i=5;i<=n;i*=5){
				sum+=n/i;
			}
		}
		cout<<sum<<'\n';
	}
}
