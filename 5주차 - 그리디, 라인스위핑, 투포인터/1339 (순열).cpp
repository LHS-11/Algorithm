#include<bits/stdc++.h>
using namespace std; 
vector<int> v;
int n,ans;
map<char,int> mp;
int a[26];
int toInt(string s){
	int sum=0; 
	for(int i=0;i<s.size();i++){
		sum*=10;
		sum+=(a[s[i]-'A']);
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	
	vector<string> str(n);
	
	for(int i=0;i<n;i++) cin >> str[i];
	
	vector<char> al;
	
	for(auto s :str){
		for(auto c : s){
			if(!mp[c]){
				al.push_back(c);
				mp[c]++;
			}
		}
	}
	
	// al 순열 돌림  
	sort(al.begin(),al.end());
	
	do{
		
		for(int i=0;i<al.size();i++){
			a[al[i]-'A']=9-i;
//			cout<<al[i]-'a'<<endl;
		}
		
		int sum=0;
		for(auto s : str){
			sum+=toInt(s);
		}
		
		ans=max(sum,ans);
		
	}while(next_permutation(al.begin(),al.end()));
		
	cout<<ans;
}
