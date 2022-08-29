#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int d,r,n;
int a[100004];
int b[100004];
vector<int>v;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> d >> r >> n;
	
	for(int i=0;i<n;i++) cin >> a[i];
	
	for(int i=0;i<n;i++) cin >> b[i];
	
	sort(a,a+n);
	sort(b,b+n);
	
	r=pow(r,2)-pow(d,2); // 24
	
	int st=0,en=0;
	for(int i=0;i<n;i++){
		
		while(st!=n && pow(a[st]-b[i],2)>r){
			st++;
		}
		if(st==n) {
			v.push_back(0);
			st=0;
			continue;
		}
		while(en!=n && pow(a[en]-b[i],2)<=r){
			en++;
		}
		
		v.push_back(en-st);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
}
