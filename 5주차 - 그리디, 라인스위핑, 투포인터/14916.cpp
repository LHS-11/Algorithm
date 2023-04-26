#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	
	int ans=1e5+4;
	
	for(int i=0;i<=n/5;i++){
		int t=n;
		int cnt=i;
		
		t-=(5*i);
		
		if(t%2==0) {
			cnt+=(t/2);
			ans=min(ans,cnt);
		}
	}
	
	if(ans==1e5+4) cout<<-1;
	else cout<<ans;

}
