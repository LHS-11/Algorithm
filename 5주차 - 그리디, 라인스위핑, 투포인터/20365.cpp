#include<bits/stdc++.h>
using namespace std;
/*
BRBRBR B 3 R 3 -> 1+3 => 4 
*/ 
int n,ans;
string s;
int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n;
	cin >> s;
	
	
	
	s.erase(unique(s.begin(),s.end()),s.end());
	
	int bcnt=0,rcnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='B') bcnt++;
		else rcnt++;
	}
	
	ans=min(bcnt,rcnt)+1;
	
	cout<<ans;
	
}
