#include<bits/stdc++.h>
using namespace std;
string board[54][54];
// merge 된거 구분
int check[54][54];
int check1[54][54];
const int sz=51;
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    int num=1;
    for(int i=0;i<54;i++){
        for(int j=0;j<54;j++){
            board[i][j]=".";
            check[i][j]=num;
            check1[i][j]=num;
            num++;
        }
    }
    for(auto c : commands){
        vector<string> cmd;
        string str="";
        for(int i=0;i<c.size();i++){
            if(c[i]==' '){
                cmd.push_back(str);
                str="";
            }else str+=c[i];
        }
        cmd.push_back(str);

        if(cmd[0]=="UPDATE"){
            if(cmd.size()==4){
                int r=stoi(cmd[1]);
                int c=stoi(cmd[2]);
                string val=cmd[3];

                int chk=check[r][c];
                for(int i=0;i<sz;i++){
                    for(int j=0;j<sz;j++){
                        if(check[i][j]==chk){
                            board[i][j]=val;
                        }
                    }
                }

            }else{
                string val1=cmd[1];
                string val2=cmd[2];
                for(int i=0;i<sz;i++){
                    for(int j=0;j<sz;j++){
                        if(board[i][j]==val1){
                            board[i][j]=val2;
                        }
                    }
                }
            }
        }
        else if(cmd[0]=="MERGE"){
            int r1=stoi(cmd[1]);
            int c1=stoi(cmd[2]);
            int r2=stoi(cmd[3]);
            int c2=stoi(cmd[4]);
            int chk1=check[r1][c1];
            int chk2=check[r2][c2];
            string bd=board[r1][c1];

            if(board[r1][c1]=="." && board[r2][c2]!="."){
                int tmp=chk1;
                chk1=chk2;
                chk2=tmp;
                bd=board[r2][c2];
            }

            for(int i=1;i<sz;i++){
                for(int j=1;j<sz;j++){
                    if(chk1==check[i][j] || chk2==check[i][j]){
                        check[i][j]=chk1;
                        board[i][j]=bd;
                    }
                }
            }

        }else if(cmd[0]=="UNMERGE"){
            int r=stoi(cmd[1]);
            int c=stoi(cmd[2]);
            int chk=check[r][c];
            string val=board[r][c];
            if(!chk) continue;
            for(int i=0;i<sz;i++){
                for(int j=0;j<sz;j++){
                    if(chk==check[i][j]){
                        check[i][j]=check1[i][j];
                        board[i][j]=".";
                    }
                }
            }
            check[r][c]=check1[r][c];
            board[r][c]=val;
        }else{
            int r=stoi(cmd[1]);
            int c=stoi(cmd[2]);
            if(board[r][c]==".") answer.push_back("EMPTY");
            else answer.push_back(board[r][c]);
        }
    }

    return answer;
}