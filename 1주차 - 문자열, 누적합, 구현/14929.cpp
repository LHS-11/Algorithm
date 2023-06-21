#include<bits/stdc++.h>
using namespace std;
/*
X1 X2 1 * -2 = -2 
X1 X3 1 * 3 = 3
X2 X3 -2 * 3 = -6
-----------------------
-5

X1 X2
X1 X3
X1 X4
------
X2 X3
X2 X4
------
X3 X4

X1*(X2+X3+X4)
X2*(X3+X4)
X3*X4

*/ 
int n,arr[100004];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n;
	
	int sum=0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sum+=arr[i];
	}
	
	int ans=0;
	for(int i=0;i<n-1;i++){
		sum-=arr[i];
		ans+=(arr[i]*sum);
	}
	
	cout<<ans;
}
