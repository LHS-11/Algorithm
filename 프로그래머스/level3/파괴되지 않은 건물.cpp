#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n=board.size();
    int m=board[0].size();
    vector<vector<int>>v(n+1,vector<int>(m+1,0));
    
    for(auto s : skill){
        int y=s[1];
        int x=s[2];
        int ny=s[3];
        int nx=s[4];
        int value=s[5];
        if(s[0]==1) value=-value;
        
        v[y][x]+=value;
        v[ny+1][x]+=(-value);
        v[y][nx+1]+=(-value);
        v[ny+1][nx+1]+=value;
    }
    
    
    for(int i=0;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            v[j][i]+=v[j-1][i];
        }
    }
    
    for(int i=0;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            v[i][j]+=v[i][j-1];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]+v[i][j]>0) answer++;
        }
    }
    

    return answer;
}