#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
map<char,int> chk;
vector<string> v;
int n;
int main(){
	cin >> n;
	string ans="";
	while(n--){
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		m[v[i][0]]++;
		if(m[v[i][0]]>=5){
			if(chk[v[i][0]]) continue;
			ans+=v[i][0];
			chk[v[i][0]]++;
		}
	}
	
	if(ans!="") cout<<ans;
	else cout<<"PREDAJA";
	return 0;
}
