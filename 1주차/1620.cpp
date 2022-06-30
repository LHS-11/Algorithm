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
		if(atoi(s.c_str())==0) // c_str -> 문자열의 첫번째 주소값 , atoi -> 문자 -> 숫자 ( 문자가 나올경우 0이 나옴, 문자+숫자 일 경우
		                       // 문자가 바로 나오면 바로 0을 반환하고 숫자가 먼저 나오면 숫자만 뽑혀서 나옴 
			cout<< m1[s]<<'\n'; 
		}else cout<< m2[stoi(s)]<<'\n';
	}
}
