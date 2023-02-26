#include<bits/stdc++.h>
using namespace std;
const int sz=104;
int board[sz][sz];
int vis[sz][sz];
int dx[8]={-1,0,1,0,-1,-1,1,1};
int dy[8]={0,-1,0,1,-1,1,-1,1};
/*
1. 직사각형을 board=2로 채우기
2. 직사각형에서 주위(상하좌우대각선)가 board가 0인 곳 있으면 1로 체크함으로써 경로 생성
3. 경로를 따라서 bfs
*/
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    for(auto r : rectangle){
        int x1=r[0]*2;
        int y1=r[1]*2;
        int x2=r[2]*2;
        int y2=r[3]*2;
        
        for(int i=y1;i<=y2;i++){
            for(int j=x1;j<=x2;j++){
                board[i][j]=2;
            }
        }
    }
    
    queue<pair<int,int>> q;
    for(int i=0;i<104;i++){
        for(int j=0;j<104;j++){
            if(board[i][j]==2){
                for(int k=0;k<8;k++){
                    int nx=j+dx[k];
                    int ny=i+dy[k];
                    if(board[ny][nx]==0){
                        board[i][j]=1;
                        break;
                    }
                }
                if(i==characterY*2 && j==characterX*2) {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
    }
    
    while(q.size()){
        auto cur=q.front();
        q.pop();
        
        if(cur.second==itemX*2 && cur.first==itemY*2){
            return vis[cur.first][cur.second]/2;
        }
        
        for(int i=0;i<4;i++){
            int nx=cur.second+dx[i];
            int ny=cur.first+dy[i];
            
            if(nx<0 || ny <0 || nx>100 || ny>100) continue;
            
            if(!vis[ny][nx] && board[ny][nx]==1){
                vis[ny][nx]=vis[cur.first][cur.second]+1;
                q.push({ny,nx});
            }
        }
    }
    
    int answer = 0;
    
    return answer;
}