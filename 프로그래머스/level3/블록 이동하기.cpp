#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int vis[104][104][104][104][2];
int solution(vector<vector<int>> board) {
    int answer = 0;
    int sz=board.size();
    queue<tuple<int,int,int,int,int,int>> q;
    q.push({0,0,1,0,0,0});
    vis[0][0][0][1][0]=1; // 0일때 가로, 1일때 세로
    
    while(q.size()){
        int x1,y1,x2,y2,cnt,sh;
        tie(x1,y1,x2,y2,cnt,sh)=q.front();
        q.pop();
        
        if((x1==sz-1 && y1==sz-1) || (x2==sz-1 && y2==sz-1)) return cnt;
        for(int i=0;i<4;i++){
            int nx1=x1+dx[i];
            int ny1=y1+dy[i];
            int nx2=x2+dx[i];
            int ny2=y2+dy[i];
                
            if(nx1<0 || ny1<0 || nx1>=sz|| ny1>=sz|| nx2<0 || ny2<0|| nx2>=sz || ny2>=sz) continue;
                
            if(vis[ny1][nx1][ny2][nx2][sh]|| board[ny1][nx1]==1 || board[ny2][nx2]==1) continue;
                
            vis[ny1][nx1][ny2][nx2][sh]=1;
            q.push({nx1,ny1,nx2,ny2,cnt+1,sh});
        }
        if(sh==0){ // 가로방향 
            
            if(x1>x2){
                int tmp=x1;
                x1=x2;
                x2=tmp;
            }
            
            // 왼쪽 기준으로 아래로 회전 
            if(y2+1<sz && !board[y2+1][x2] && !board[y2+1][x2-1]){
                if(!vis[y1][x1][y2+1][x2-1][1]){
                vis[y1][x1][y2+1][x2-1][1]=1;
                q.push({x1,y1,x1,y2+1,cnt+1,1});
                }
            }
            
            //왼쪽 기준으로 위로 회전
            if(y2-1>=0 && !board[y2-1][x2] && !board[y2-1][x2-1]){
                if(!vis[y1][x1][y2-1][x2-1][1]){
                vis[y1][x1][y2-1][x2-1][1]=1;
                q.push({x1,y1,x1,y2-1,cnt+1,1});
                }
            }
            //오른쪽 기준으로 아래로 회전 
            if(y2+1<sz && !board[y1+1][x1] && !board[y1+1][x1+1]){
                if(!vis[y1+1][x1+1][y2][x2][1]){
                vis[y1+1][x1+1][y2][x2][1]=1;
                q.push({x1+1,y1+1,x2,y2,cnt+1,1});
                }
            }
            
            //오른쪽 기준으로 위로 회전
            
            if(y2-1>=0 && !board[y1-1][x1] && !board[y1-1][x1+1]){
                if(!vis[y1-1][x1+1][y2][x2][1]){
                vis[y1-1][x1+1][y2][x2][1]=1;
                q.push({x1+1,y1-1,x2,y2,cnt+1,1});
                }
            }
            
        }
        else{ // 세로 방향
            //위쪽 기준으로 오른쪽으로 회전
            if(y1>y2){
                int tmp=y1;
                y1=y2;
                y2=tmp;
            }
            if(x2+1<sz && !board[y2][x1+1] && !board[y1][x1+1]){
                if(!vis[y1][x1][y1][x1+1][0]){
                vis[y1][x1][y1][x1+1][0]=1;
                q.push({x1,y1,x1+1,y1,cnt+1,0});
                }
            }
            //위쪽 기준으로 왼쪽 회전
            
            if(x2-1>=0 && !board[y2][x1-1] && !board[y1][x1-1]){
                if(!vis[y1][x1][y1][x1-1][0]){
                vis[y1][x1][y1][x1-1][0]=1;
                q.push({x1,y1,x1-1,y1,cnt+1,0});
                }
            }
            // //아래쪽 기준으로 오른쪽으로 회전
            if(x2+1<sz && !board[y1][x1+1] && !board[y2][x1+1]){
                if(!vis[y2][x1+1][y2][x2][0]){
                vis[y2][x1+1][y2][x2][0]=1;
                q.push({x1+1,y2,x2,y2,cnt+1,0});
                }
            }
            // // 아래쪽 기준으로 왼쪽으로 회전 
            if(x2-1>=0 && !board[y1][x1-1] && !board[y2][x1-1]){
                if(!vis[y2][x1-1][y2][x2][0]){
                vis[y2][x1-1][y2][x2][0]=1;
                q.push({x1-1,y2,x2,y2,cnt+1,0});
                }
            }
        }
        
    }
    
    
    return answer;
}