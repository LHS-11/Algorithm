#include<bits/stdc++.h>
using namespace std;
/*
열쇠는 회전과 이동이 가능
-> 완탐, 시뮬레이션
자물쇠의 board는 두배로 확장을 한 뒤 열쇠를 하나하나 맞춘다음 4번 돌려서 맞는지 확인
*/
vector<vector<int>> rotate(vector<vector<int>>& b){
    vector<vector<int>>v=b;
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b.size();j++){
            v[j][i]=b[b.size()-i-1][j];
        }
    }
    return v;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int k_sz=key.size();
    int l_sz=lock.size();
    
    int b_sz=2*k_sz+l_sz-2;
    //1. lock -> board 만들기
    vector<vector<int>>board(b_sz,vector<int>(b_sz,1));
    
    for(int i=k_sz-1;i<=l_sz+k_sz-2;i++){
        for(int j=k_sz-1;j<=l_sz+k_sz-2;j++){
            board[i][j]=lock[i-k_sz+1][j-k_sz+1];
        }
    }
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    
    
    //2. 열쇠를 홈에 맞추기
    for(int i=0;i<b_sz-(k_sz-1);i++){
        for(int j=0;j<b_sz-(k_sz-1);j++){
            vector<vector<int>>ky=key;
            for(int k=0;k<4;k++){
                vector<vector<int>>bd=board;
                
                for(int a=0;a<k_sz;a++){
                    for(int b=0;b<k_sz;b++){
                        // 열쇠의 돌기와 자물쇠의 돌기가 만나서는 안됩니다.
                        if(bd[i+a][j+b]!=ky[a][b] &&board[i+a][j+b]==0){
                            bd[i+a][j+b]=2;
                        }
                        if(bd[i+a][j+b]==1 && ky[a][b]==1) bd[i+a][j+b]=0;
                    }
                }
                
                int flag=0;
                for(int i=k_sz-1;i<=l_sz+k_sz-2;i++){
                    for(int j=k_sz-1;j<=l_sz+k_sz-2;j++){
                        if(!bd[i][j]) {
                            flag=1;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(!flag) return true;
                // 90도씩 회전
                ky=rotate(ky);
            }
        }
    }
    return false;
}