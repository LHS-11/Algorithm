#include<bits/stdc++.h>
using namespace std;
const int MAX = 16;
const int INF = 1e9;
int n,arr[MAX][MAX],p,bit,vis[1<<MAX];
string str;
int count(int bit){
	int cnt=0;
	while(bit){
		if(bit & 1) cnt++;
		bit=bit>>1;
	}
	return cnt;
}
int go(int bit){
	if(count(bit)>=p) return 0;
	
	int& rst=vis[bit];
	
	if(rst!=-1) return rst;
	
	rst=INF;
	for(int i=0;i<n;i++){
		if(!(bit & (1<<i))) continue; // 고장나지 않은 발전소를 선택 
		for(int j=0;j<n;j++){
			if(!(bit & (1<<j))){ // 고장난 발전소를 선택 
				int nxt_bit=bit | (1<<j);
				rst=min(rst,arr[i][j]+go(nxt_bit));
			}
		}
	}
	return rst;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	/*
	
	DFS + DP (메모이제이션) + 비트마스킹  
	 
	*/
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>> arr[i][j];
		}
	}
	
	cin >> str;
	for(int i=0;i<n;i++) {
		if(str[i]=='Y') bit |= (1<<i);
	}
	cin >> p;
	
	memset(vis,-1,sizeof(vis));
	int ans=go(bit);
	
	if(ans==INF) cout<< -1;
	else cout<<ans;
}
