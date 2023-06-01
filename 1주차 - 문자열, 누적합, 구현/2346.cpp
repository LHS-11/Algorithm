#include<bits/stdc++.h>
using namespace std;
/*
5
3 2 1 -3 -1

-3 -1 3 2 1

-1 3 2 1

3 2 1 -1 

2 1 -1

1 -1 2
-1 2 1
2 1 -1

2 1 -1	
 
*/
int n;
int chk[1004];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n;
	
	deque<pair<int,int>> dq;
	
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		dq.push_back(make_pair(i,x));
	}
	
	vector<int> ans;
	while(dq.size()){
		auto cur=dq.front();
		ans.push_back(cur.first);
		dq.pop_front();
		
		if(cur.second>0){ // <-
			for(int i=0;i<cur.second-1;i++){
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}else{
			for(int i=0;i<cur.second*(-1);i++){
				dq.push_front(dq.back());
				dq.pop_back();
			}			
		}
	}
	
	for(auto& a : ans) cout<<a<<' ';
}
