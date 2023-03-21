#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,-1,1,0}; //d,l,r,u;
int dy[4]={1,0,0,-1};
string dir="dlru";
string ans;
int flag=0;
void go(int n, int m, int x, int y, int r, int c, int k,int cnt, string str){
   
    if(flag) return;
    
    if(x==c && y==r && k==cnt){
        ans=str;
        flag=1;
        return;
    }
    
    if(cnt + abs(x-c) + abs(y-r) > k) return;
    
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx<1 || ny<1 || nx>m ||ny>n) continue;
        string sstr=str;
        sstr+=dir[i];
        if(cnt<k) go(n,m,nx,ny,r,c,k,cnt+1,sstr);
    }
    
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int dis=abs(x-r)+abs(y-c); // 출발지에서 도착지까지의 거리 
    if(dis>k || (k-dis)%2==1) return "impossible";
    
    go(n,m,y,x,r,c,k,0,"");
    
    return ans;
}
