#include<bits/stdc++.h>
using namespace std;
int a,t,c;
int arr[]={0,1,0,1};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> a >> t>>c; 
	
	int ans=0;
	int idx=2;
	while(t){
		int flag=0;
		for(int i=0;i<4;i++){
			if(arr[i]==c){
				t--;
			}
			if(t==0){
				flag=1;
				break;
			}
			ans++;
		}
		
		if(flag){
			break;
		}
		
		for(int i=0;i<idx;i++){
			if(0==c){
				t--;
			}
			if(t==0){
				flag=1;
				break;
			}
			ans++;
		}
		
		if(flag){
			break;
		}
		
		for(int i=0;i<idx;i++){
			if(1==c){
				t--;
			}
			if(t==0){
				flag=1;
				break;
			}
			ans++;
		}
		
		if(flag){
			break;
		}
		
		idx++;
	}
	cout<<ans%a;
	
	
}
