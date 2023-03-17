#include<bits/stdc++.h>
using namespace std;
/*
어떤 방향을 선택했을 때 벽이나 장애물에 도달했을때만 멈출 수 있다 
*/
int vis[104][104][4];
int dx[5]={0,-1,0,1,0}; // 서, 북, 동 , 남
int dy[5]={0,0,-1,0,1};
int solution(vector<string> board) {
    int answer = 0;
    
    queue<tuple<int,int,int,int>> q;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]=='R') {
                q.push({i,j,0,0});
                vis[i][j][0]=1;
            }
        }
    }
    
    int ysz=board.size();
    int xsz=board[0].size();
    while(q.size()){
        int y,x,dir,cnt;
        tie(y,x,dir,cnt)=q.front();
        q.pop();
        
        if(board[y][x]=='G') return cnt;
        
        for(int i=1;i<=4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            while(1){
                if(ny==ysz || nx == xsz || nx==-1 || ny==-1) break;
                if(board[ny][nx]=='D') break;
                nx+=dx[i];
                ny+=dy[i];
            }
            nx-=dx[i];
            ny-=dy[i];
            if(!vis[ny][nx][i]){
                vis[ny][nx][i]=1;
                q.push({ny,nx,i,cnt+1});
            }
        }
    }
    return -1;
}