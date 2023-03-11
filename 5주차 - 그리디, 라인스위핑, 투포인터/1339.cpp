/*
Boj 1339
ó�� ���� ū �ڸ��� ���ں��� ū ���� �����ϴ°� Best X 
-> �ݷʰ� ����, �ִ� 10�������̱� ������ �� ���ڸ��� ������ �� �ϱ� ����
100A+10B+C -> �̷������� �� �ڸ������� ���ĺ��� �������� �����ϰ� ���׽��� ���� ���������ؼ� ���� 

�� ������ ��Ʈ��ŷ���� Ǯ ���� �ִ� ���� 10! => �뷫 360��  
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

