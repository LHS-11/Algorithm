#include<bits/stdc++.h>
using namespace std;
/*
사이클이 무조건 생기기 때문에 모든 격자점에서 4방향이 사용되어야 함
각 격자마다 4방향이 사용되지 않았으면, 사용 안된 사이클을 탐색 
*/
int arr[504][504][8],xsz,ysz;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<int> ans;
vector<string> grid;
int change(int i,int j,int k){
    
    int dir=k; // 왼쪽, 오른쪽, 위, 아래 
    if(grid[i][j]=='R'){
        if(k==0) dir=2; // 위쪽
        else if(k==1) dir=3; // 아래쪽
        else if(k==2) dir=1; // 오른쪽 
        else dir=0; // 왼쪽 
    }else if(grid[i][j]=='L'){
        if(k==0) dir=3;
        else if(k==1) dir=2;
        else if(k==2) dir=0;
        else dir=1;
    }
    return dir;
}
void go(int i,int j,int k){
    
    queue<tuple<int,int,int>>q;
    
    q.push({i,j,k});
    arr[i][j][k]=1;
    int cnt=0;
    
    while(q.size()){
        int x,y,dir;
        tie(y,x,dir)=q.front();
        q.pop();
        cnt++;
        
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        
        if(nx<0){
            nx=xsz-1;
        }else if(nx>=xsz){
            nx=0;
        }
        
        if(ny<0){
            ny=ysz-1;
        }else if(ny>=ysz){
            ny=0;
        }
        
        dir=change(ny,nx,dir);
        if(!arr[ny][nx][dir]){
            arr[ny][nx][dir]=1;
            q.push({ny,nx,dir});
        }
    }
    
    ans.push_back(cnt);
}
vector<int> solution(vector<string> g) {
    vector<int> answer;
    grid=g;
    ysz=grid.size();
    xsz=grid[0].size();
    
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            for(int k=0;k<4;k++){
                
                if(!arr[i][j][k]){ // 사이클 탐색 
                    go(i,j,k);
                }
            }
        }
    }
    
    sort(ans.begin(),ans.end());
    return ans;
}