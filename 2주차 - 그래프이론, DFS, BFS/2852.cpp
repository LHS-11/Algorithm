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
	int flag=1; // ������  
	for(int i=1;i<v.size();i++){
		if(v[i].first!=t){ // � ���� �̱�� �ִµ�, �ٸ� ���� ���� �־��� �� 
			flag--;
			if(flag<0) { // ���� ��Ȳ���� �ٸ� ���� ���� �־��� �� ������ �߻� (ex) a �� ��, b �� ��, �ٽ� �� a���� ��) 
				flag=1;
				t=v[i].first;
				ts=v[i].second;
			}
			if(!flag){ // ���� ��Ȳ�� �����ϱ�, �� ���� �̰Ŵ� �� �̱�� �ð� ���� 
				score[t]+=v[i].second-ts;
				t=v[i].first;
				ts=v[i].second;
			}			
		}else{ // ���� ��Ȳ���� ���� ���� ���� �־��� �� ( �������� ���� ��) 
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
