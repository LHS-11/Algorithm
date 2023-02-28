#include<bits/stdc++.h>
using namespace std;
/*
설치 
보 
1. 양쪽 끝 부분에 보가 있으면 설치 가능
2. 기둥 위에 있으면 설치 가능

기둥
1. 바닥 위
2. 보의 한쪽 끝 부분 위
3. 다른 기둥 위 

삭제 
보 
1. 양 옆의 보가 존재시 삭제 X 
2. 기둥이 삭제하려는 보의 위에 존재시 삭제 X

기둥  
1. 삭제하려는 기둥 위에 보가 존재시 삭제 X 
2. 삭제하려는 기둥 아래에 기둥이 존재하거나 위에도 기둥이 존재하면 삭제 X 
*/
int a[104][104]; // 기둥
int b[104][104]; // 보
bool check(int k, int x,int y){
    
    if(k==1){ // 보 
        //1. 양쪽 끝 부분에 보가 있으면 설치 가능
        if((x-1>=0 && b[y][x-1]) && b[y][x+1]) return true;
        // 2. 기둥 위에 있으면 설치 가능
        if((y-1>=0 && a[y-1][x]) || (y-1>=0 && a[y-1][x+1])) return true;
    }else{ // 기둥
        // 1. 바닥 위
        if(y==0) return true;
        // 2. 보의 한쪽 끝 부분 위
        if((x-1>=0 && b[y][x-1]) || b[y][x]) return true;
        // 3. 다른 기둥 위 
        if(y-1>=0 && a[y-1][x]) return true;
    }
    return false;
}
void rmCheck(int k,int x,int y){
    
    int flag=0;
    if(k==1){ // 보 
        b[y][x]=0;
    // 1. 양 옆의 보가 존재시 삭제 X 
        if(x-1>=0 && b[y][x-1] && !check(1,x-1,y) ) flag=1;
        if(b[y][x+1] && !check(1,x+1,y) ) flag=1;
    // 2. 기둥이 삭제하려는 보의 위에 존재시 삭제 X
        if(a[y][x] && !check(0,x,y)) flag=1;
        if(a[y][x+1] && !check(0,x+1,y)) flag=1;
    }else{ // 기둥
    // 1. 삭제하려는 기둥 위에 보가 존재시 삭제 X 
        a[y][x]=0;
        if(b[y+1][x] && !check(1,x,y+1)) flag=1;
        if(x-1>=0 && b[y+1][x-1] && !check(1,x-1,y+1)) flag=1;
    // 2. 삭제하려는 기둥 아래에 기둥이 존재하거나 위에도 기둥이 존재하면 삭제 X 
        if(a[y+1][x] && !check(0,x,y+1)) flag=1;

    }
    
    if(flag){
        if(k==1){
            b[y][x]=1;
        }else a[y][x]=1; 
    }
    
    
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(auto bd:build_frame){
        int x=bd[0];
        int y=bd[1];
        int k=bd[2];
        int r=bd[3];
        
        if(r==0){ // 삭제
            rmCheck(k,x,y);
        }else{ // 설치 
            if(k==1){ // 보
                if(check(k,x,y)) b[y][x]=1;
            }else{  // 기둥
                if(check(k,x,y)) a[y][x]=1;
            }
        }
    }
    
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(a[i][j]){
                answer.push_back({j,i,0});
            }
            if(b[i][j]){
                answer.push_back({j,i,1});
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}