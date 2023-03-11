/*
Boj 1339
처음 생각 큰 자릿수 문자부터 큰 수를 배정하는게 Best X 
-> 반례가 존재, 최대 10개까지이기 때문에 맨 앞자리만 가지고 비교 하기 보다
100A+10B+C -> 이런식으로 각 자릿수마다 알파벳을 미지수로 생각하고 다항식을 만들어서 내림차순해서 구함 

이 문제는 백트래킹으로 풀 수도 있는 문제 10! => 대략 360만  
*/
#include<bits/stdc++.h>
using namespace std;
int N;
map<char,int>mp;
map<char,int>n;
vector<char> pl[10];
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first>b.first;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	vector<string> v(N);
	
	
	for(int i=0;i<N;i++) {
		cin >> v[i];
		for(int j=0;j<v[i].size();j++) {
			mp[v[i][j]]+=pow(10,v[i].size()-1-j);
		}
	}
	
	vector<pair<int,char>> vt;
	for(auto value :mp){
		vt.push_back({value.second,value.first});	
	}
	
	sort(vt.begin(),vt.end(),cmp);
	
	int mx=9;
	for(auto x :vt){
		n[x.second]=mx;
		mx--;
	}
	
	int ans=0;
	for(int i=0;i<N;i++){
		string str="";
		for(auto c : v[i]) str+=(n[c]+'0');
		
		ans+=stoi(str);
	}
	
	cout<<ans;
	
	
} 

