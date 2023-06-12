#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[1004];
/*
해당 자리에서 가장 많은 알파벳 선택  
*/
bool cmp(pair<int,int> a, pair<int,int > b){
	if(a.first==b.first) return a.second<b.second;
	return a.first>b.first;
}
int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++) cin >> s[i];

	int cnt=0;
	string ans="";
	for(int i=0;i<m;i++){
		
		/*
		각 자릿수에서 가장 많이 공통된 것 중에 가장 빠른 알파벳  
		*/
		int a[26];
		fill(a,a+26,0);
		char c=s[0][i];
		for(int j=0;j<n;j++){
			a[s[j][i]-'A']++;
		}
		
		vector<pair<int,int>> v;
		
		for(int k=0;k<26;k++){
			v.push_back(make_pair(a[k],k));
		}
		
		sort(v.begin(),v.end(),cmp);
		ans+=(char)('A'+v[0].second);
	} 
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ans[j]!=s[i][j]){
				cnt++;
			}
		}
	}
	
	cout<<ans<<'\n'<<cnt;
}
