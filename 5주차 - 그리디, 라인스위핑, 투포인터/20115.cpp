#include<bits/stdc++.h>
using namespace std;
/*
5
3 2 10 9 6

10 9 6 3 2

11 9 6 3
10 + 1 = 11

12 9 6
11 + 3/2 = 11 + 1 = 12

12 + 6/2 = 15

15 9
15 + 9/2 = 15 + 4 = 19


*/
int n;
long double ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n;
	
	vector<double> v(n);
	
	for(int i=0;i<n;i++) cin >> v[i];
	
	sort(v.begin(),v.end(),greater<>());
	
	stack<long double> stk;
	
	int en=v.size()-1;
	stk.push(v[0]);
	while(stk.size()){
		auto cur=stk.top();
		stk.pop();
		
		if(en==0){
			ans=cur;
			break;
		}
		
		cur+=(v[en--]/2);
		stk.push(cur);
	}
	
	cout<<ans;
	
}
