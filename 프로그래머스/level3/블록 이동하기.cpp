#include<bits/stdc++.h>
using namespace std;
/*
왼쪽,오른쪽으로 회전하는 로직

좌우 움질일 수 있지만 두칸을 차지하고 있기 때문에 두칸을 다 같이 고려해야함 
*/
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int solution(vector<vector<int>> board) {
    int answer = 0;
    int sz=board.size();
    
    queue<tuple<int,int,int,int,int>> q;
    q.push({0,0,1,0,0});
    
    while(q.size()){
        int x1,y1,x2,y2,cnt;
        tie(x1,y1,x2,y2,cnt)=q.front();
        q.pop();
        
        if((x1==sz-1 && y1==sz-1) || (x2==sz-1 && y2==sz-1)) 
            return cnt;
        
        for(int i=0;i<8;i++){
            
            if(i<4){
                int nx1=x1+dx[i];
                int ny1=y1+dy[i];
                int nx2=x2+dx[i];
                int ny2=y2+dy[i];
                
                if(nx1<0 || nx2 < 0 || ny1 < 0 || ny2 <0 || nx1>=100 || nx2 >=100 || ny1>=100 || ny2>=100) continue;
                
                if(board[ny1][nx1]==1 || board[ny2][nx2]==1) continue;
                
                q.push({nx1,ny1,nx2,ny2,cnt+1});
            
            }
            else if(i==4){ // 오른쪽 날개를 축으로 90도 회전 및 270도 회전
                // 위로 회전
                int nx1=x1+1;
                int ny1=y1-1;
                if(nx1<0 || ny1 < 0  || nx1>=100  || ny1>=100 || board[y1-1][x1]==1) continue;
                if(board[ny1][nx1]==1) continue;
                q.push({nx1,ny1,x2,y2,cnt+1});
            }else if(i==5){   
                // 아래로 회전
                int nx1=x1+1;
                int ny1=y1+1;
                if(nx1<0 || ny1 < 0  || nx1>=100  || ny1>=100 || board[y1+1][x1]==1) continue;
                if(board[ny1][nx1]==1) continue;
                q.push({nx1,ny1,x2,y2,cnt+1});
                
            }else if(i==6){ // 왼쪽 날개를 축으로 90도 회전 및 270도 회전 
                // 위로 회전
                int nx2=x2-1;
                int ny2=y2-1;
                if(nx2<0 || ny2 < 0  || nx2>=100  || ny2>=100 || board[y2-1][x2]==1) continue;
                if(board[ny2][nx2]==1) continue;
                q.push({x1,y1,nx2,ny2,cnt+1});
            }else if(i==7){
                // 아래로 회전
                int nx2=x2-1;
                int ny2=y2+1;
                if(nx2<0 || ny2 <0  || nx2>=100  || ny2>=100 || board[y2+1][x2]==1) continue;
                if(board[ny2][nx2]==1) continue;
                q.push({x1,y1,nx2,ny2,cnt+1});
            }
        }
    }
    return answer;
}