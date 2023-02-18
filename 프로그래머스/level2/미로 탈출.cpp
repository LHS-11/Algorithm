#include<bits/stdc++.h>
using namespace std;
int vis[104][104];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int xsz,ysz;
int go(int y1,int x1,vector<string> maps){
    
    memset(vis,0,sizeof(vis));
    
    queue<tuple<int,int,int>> q;
    q.push({y1,x1,0});
    vis[y1][x1]=1;
    while(q.size()){
        int x,y,cnt;
        tie(y,x,cnt)=q.front();
        q.pop();
                    
        if(maps[y][x]=='E'){
            return cnt;
        }
                    
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
                        
            if(nx<0 || ny<0 ||ny>=ysz || nx>=xsz) continue;
                        
            if(!vis[ny][nx] && maps[ny][nx]!='X'){
                q.push({ny,nx,cnt+1});
                vis[ny][nx]=1;
                    }
                }
            }
    
    return -1;
}
int solution(vector<string> maps) {
    int answer = 0;
    
    xsz=maps[0].size();
    ysz=maps.size();
    for(int i=0;i<ysz;i++){
        for(int j=0;j<xsz;j++){
            if(maps[i][j]=='S'){
                queue<tuple<int,int,int>> q;
                q.push({i,j,0});
                vis[i][j]=1;
                while(q.size()){
                    int x,y,cnt;
                    tie(y,x,cnt)=q.front();
                    q.pop();
                    
                    if(maps[y][x]=='L'){
                        int flag=go(y,x,maps);
                        if(flag<0){
                            return -1;
                        }else{
                            return flag+cnt;
                        }
                    }
                    
                    for(int i=0;i<4;i++){
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        
                        if(nx<0 || ny<0 ||ny>=ysz || nx>=xsz) continue;
                        
                        if(!vis[ny][nx] && maps[ny][nx]!='X'){
                            q.push({ny,nx,cnt+1});
                            vis[ny][nx]=1;
                        }
                    }
                }
            }
        }
    }
    
    
    return -1;
}