#include<bits/stdc++.h>
using namespace std;
int n,m,j;
int a[21];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> m >> j;
	
	for(int i=0;i<j;i++) cin >> a[i];
	
	int left=1;
	int right=m;
	
	int ans=0;
	for(auto c : a){
		if(c>right){
			ans+=c-right;
			right=c;  
			left=right-m+1;
		}else if(c<left){
			ans+=left-c;
			left=c;
			right=left+m-1;
		}
	}
	
	cout<<ans;
	
}
