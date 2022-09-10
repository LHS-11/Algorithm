#include<bits/stdc++.h>
using namespace std;
int cost[4];
int cnt[104];
vector<pair<int,int> > bus;
int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);
	
	int a,b,c;
	cin >> a >> b >> c;
	cost[1]=a; cost[2]=b; cost[3]=c;
	
	int mn=105,mx=0;
	for(int i=1;i<=3;i++){
		int a,b;
		cin >> a >> b;
		if(mn>a) mn=a;
		if(mx<b) mx=b;
		for(int j=a;j<b;j++) cnt[j]++;
	}

	int st=mn;
	int sum=0;
	for(int i=mn+1;i<=mx;i++){
		if(cnt[st]==cnt[i]) continue;
		sum+=cost[cnt[st]]*(i-st)*cnt[st];
		st=i;
	}
	cout<<sum;
	
}
