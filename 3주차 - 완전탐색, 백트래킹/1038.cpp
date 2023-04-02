#include<bits/stdc++.h>
using namespace std;
int n,cnt;
map<string,int> vis;
vector<long long> v;
/*
최대로 나올 수 있는 수는 9876543210 이기 때문에 기저조건을 str.size()>=10 으로 두면 됨 
*/
void go(string str){
	
	if(str.size()>=10) return;
	
	
	int now=stoll(str);
	for(int i=0;i<=9;i++){
		if(now%10>i){
			string s=str+to_string(i);
			v.push_back(stoll(s));
			go(s);
			s.pop_back();
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	
	for(int i=0;i<=9;i++){
		v.push_back(i);
		go(to_string(i));
	}
	sort(v.begin(),v.end());
	
	if(v.size()<=n) cout<<-1;
	else cout<<v[n];
	
}
