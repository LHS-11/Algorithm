#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		vector<string> v;
	
		map<string,int> m;
		
		
		for(int i =0;i<n;i++){
			string s1,s2;
			cin >> s1 >> s2;
			if(!m[s2]) v.push_back(s2);
			m[s2]++;
			
		}
		int ans=1;
		for(int i=0;i<v.size();i++){
			m[v[i]]++;
			ans*=m[v[i]];
		}
		
		cout<<ans-1<<'\n';
		
	}
}

