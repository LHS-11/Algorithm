#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
/*
2. 가로, 세로, 대각선으로 3개가 이미 만들어졌는지 체크 
*/

int check(vector<string> board,char c){
    int cnt=0;
    // 가로
    for(int i=0;i<3;i++){
        if(board[i][0]==c && board[i][0]==board[i][1] && board[i][0]==board[i][2]){
                    cnt++;
        }    
    }
    // 세로
    for(int i=0;i<3;i++){
        if(board[0][i]==c && board[0][i]==board[1][i] && board[0][i]==board[2][i]){
                    cnt++;
        }    
    }
    //대각선
    
    if(board[1][1]==c && board[1][1]==board[2][2] && board[1][1]==board[0][0]) cnt++;
    if(board[1][1]==c && board[1][1]==board[0][2] && board[1][1]==board[2][0]) cnt++;
    
    return cnt;
}
int solution(vector<string> board) {
    int answer = -1;
//     1. O,X 갯수가 다르거나 X의 갯수가 O의 갯수보다 더 많은지 체크
//      1-1. O의 갯수보다 X의 갯수가 더 많은지
//      1-2. O의 갯수가 X의 갯수보다 2개이상 많은지
    
    int oCnt=0,xCnt=0;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]=='O'){
                oCnt++;
            }else if(board[i][j]=='X'){
                xCnt++;
            }
        }
    }
    
    if(oCnt<xCnt || oCnt>xCnt+1){
        return 0;
    }else {
        int oWinCnt=check(board,'O');
        int xWinCnt=check(board,'X');
        
        if (oWinCnt > 0) { // O가 먼저 만들었을 경우
            if (oCnt == xCnt)
                return 0;
        }
        if (xWinCnt > 0) { // X가 먼저 만들었을 경우
            if (oCnt > xCnt )
                return 0;
        }
    }
     
    return 1;
}