#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> a >> b >> c >> d  >> e >> f;
	
	int x,y;
	for(x=-999;x<=999;x++){
		int flag=0;
		for(y=-999;y<=999;y++){
			if(a*x+b*y==c && d*x+e*y==f){
				flag=1;
				break;	
			}
		}
		if(flag) break;
	}
	
	cout<<x<<' '<<y;
}
