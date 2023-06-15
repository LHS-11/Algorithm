#include<bits/stdc++.h>
using namespace std;
int n,st[104],ba[104];
string str[104];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> str[i] >> st[i]>> ba[i];
	}
	
	int cnt=0;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			for(int k=1;k<=9;k++){
				bool flag=false;
				
				if(i==j || i==k || j==k) continue;
				for(int t=0;t<n;t++){
					int strike=0,ball=0;					
					// strike °¹¼ö ¼¼±â 
					if(str[t][0]==i+'0'){
						strike++;
					}
					if(str[t][1]==j+'0'){
						strike++;
					}
					if(str[t][2]==k+'0'){
						strike++;
					}		
					
					// ball °¹¼ö ¼¼±â  
					if(str[t][0]==j+'0'|| str[t][0]==k+'0'){
						ball++;
					}
					if(str[t][1]==i+'0'|| str[t][1]==k+'0'){
						ball++;
					}
					if(str[t][2]==i+'0'|| str[t][2]==j+'0'){
						ball++;
					}
					
					if(st[t]!=strike ||  ba[t]!=ball) flag=true;
				}
				if(!flag) {
					cout<<i<<j<<k<<endl;
					cnt++;
				}
				
			}
		}
	}
	
	cout<<cnt;
}
