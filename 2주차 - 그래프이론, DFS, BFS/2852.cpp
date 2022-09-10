#include<bits/stdc++.h>
using namespace std;
int score[3];
int n;
vector<pair<int,int>> v;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n;
	
	while(n--){
		int x;
		string y;
		cin>> x>> y;
		int t= stoi(y.substr(0,2))*60+stoi(y.substr(3,5));
		v.push_back({x,t});
	}
	
	int end=48*60; 
	int t=v[0].first; 
	int ts=v[0].second;
	int flag=1; // 점수차  
	for(int i=1;i<v.size();i++){
		if(v[i].first!=t){ // 어떤 팀이 이기고 있는데, 다른 팀이 골을 넣었을 때 
			flag--;
			if(flag<0) { // 동점 상황에서 다른 팀이 골을 넣었을 때 점수차 발생 (ex) a 팀 골, b 팀 골, 다시 또 a팀이 골) 
				flag=1;
				t=v[i].first;
				ts=v[i].second;
			}
			if(!flag){ // 동점 상황이 됐으니깐, 그 전에 이거던 팀 이기던 시간 갱신 
				score[t]+=v[i].second-ts;
				t=v[i].first;
				ts=v[i].second;
			}			
		}else{ // 동점 상황에서 같은 팀이 골을 넣었을 때 ( 점수차가 나게 됨) 
			if(!flag){ 
				t=v[i].first;
				ts=v[i].second;
			}
			flag++;
		}
	}
	if(flag) score[t]+=end-ts;
	score[1]/60>=0 && score[1]/60<10 ? cout<<0<<score[1]/60 : cout<<score[1]/60;
	cout<<":";
	score[1]%60>=0 && score[1]%60<10 ? cout<<0<<score[1]%60 : cout<<score[1]%60;
	cout<<'\n';
	score[2]/60>=0 && score[2]/60<10 ? cout<<0<<score[2]/60 : cout<<score[2]/60;
	cout<<":";
	score[2]%60>=0 && score[2]%60<10 ? cout<<0<<score[2]%60 : cout<<score[2]%60;
	
}
