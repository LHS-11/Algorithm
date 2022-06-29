#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,int> m1;
map<int,string>m2;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		string s;
		cin >> s;
		m1[s]=i;
		m2[i]=s;
	}
	
	while(m--){
		string s;
		cin >> s;
		if(isdigit(s[0])==0){ // isdigit(char형) -> 문자일 경우 무조건 0이 나오고 숫자면 0이 아닌 다른값
			cout<< m1[s]<<'\n'; 
		}else cout<< m2[stoi(s)]<<'\n';
	}
}
