#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int t;
/*
지나간 좌표의 x,y의 최대,최소를 구하면 됨  
*/
const int MAX=504;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1}; 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> t;
	
	while(t--){
		
		string s;
		cin >> s;
		// 동 0 , 남 1 , 서 2 , 북 3 
		//
		int x=0,y=0,dir=3;
		
		int mnX=0,mnY=0;
		int mxX=0,mxY=0;
		for(auto c : s ){
			if(c=='F'){
				x+=dx[dir];
				y+=dy[dir];
			}else if(c=='B'){
				x+=dx[(dir+2)%4];
				y+=dy[(dir+2)%4];
			}else if(c=='L'){
				dir=(dir+3)%4;
			}else{
				dir=(dir+1)%4;
			}
//			cout<<"x : "<<x<<' '<<"y : "<<y<<endl;
			mnX=min(mnX,x);
			mnY=min(mnY,y);
			mxX=max(mxX,x);
			mxY=max(mxY,y);
		}
//		cout<<mxX<<' '<<mnX<<endl;
		int l=abs(mxX-mnX);
		int w=abs(mxY-mnY);
		
//		cout<<l<<' '<<w<<'\n';
		cout<<l*w<<'\n';
	}
} 
