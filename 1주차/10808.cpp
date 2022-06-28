#include<bits/stdc++.h>
using namespace std;
int cnt[26];
//a b c d e f g h i j k l m n o p q r s t u v w x y z
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> s;
	
	for(int i=0;i<s.size();i++){
		cnt[s[i]-'a']++;
	}
	
	for(int i=0;i<26;i++){
		cout<<cnt[i]<<' ';
	}
}
