#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> k;
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<60;j++){
			for(int r=0;r<60;r++){
				if(i/10==k || i%10==k || j%10==k ||j/10==k|| r%10==k||r/10==k) cnt++;
			}
		}
	}
	
	cout<<cnt;
}
