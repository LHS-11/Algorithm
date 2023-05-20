#include<bits/stdc++.h>
using namespace std;
/*
1. 모양 적출하기 => 해당 좌표를 가져오기 (정렬 후 첫번째 값을 기준으로 상대 위치를 구함)
2. 각 좌표에 대해서 90도로 회전해서 4번 비교 

(0 , 1) (0 , 2) (1, 1)

*/
int vis[54][54];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
vector<vector<pair<int,int>>> v;
vector<vector<int>> rotate(vector<vector<int>>& t){
    
    vector<vector<int>> tmp;
    
    for(int i=0;i<t[0].size();i++){
        vector<int> vt;
        for(int j=t.size()-1;j>=0;j--){
            vt.push_back(t[j][i]);
        }
        tmp.push_back(vt);
    }
    
    return tmp;
    
}
bool isValid(vector<pair<int,int>>& vt, vector<vector<int>>& board){
    
    int vis1[54][54];
    memset(vis1,0,sizeof(vis1));
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(!board[i][j] && !vis1[i][j]){
                queue<pair<int,int>> q;
                vector<pair<int,int>> vtt;
                q.push({i,j});
                vtt.push_back({i,j});
                vis1[i][j]=1;
                
                while(q.size()){
                    auto cur=q.front();
                    q.pop();
                    
                    for(int k=0;k<4;k++){
                        int nx=cur.second+dx[k];
                        int ny=cur.first+dy[k];
                        
                        if(nx<0 || ny<0 || nx>=board[0].size() || ny>=board.size()) continue;
                        
                        if(!vis1[ny][nx] && !board[ny][nx]){
                            q.push({ny,nx});
                            vis1[ny][nx]=1;
                            vtt.push_back({ny,nx});
                        }
                    }
                }
                
                vector<pair<int,int>> vttt=vtt;
                sort(vttt.begin(),vttt.end());
                for(int k=1;k<vttt.size();k++){
                    vttt[k]={vttt[k].first-vttt[0].first,vttt[k].second-vttt[0].second};
                }
                vttt[0]={0,0};
                
                // vt랑 vtt 비교
                if(vt.size()==vttt.size()){
                    int flag=0;
                    for(int k=0;k<vt.size();k++){
                        if(!(vt[k].first==vttt[k].first && vt[k].second==vttt[k].second)){
                            flag=1;
                            break;
                        }
                    }
                    if(!flag){
                        for(auto p : vtt){
                            board[p.first][p.second]=1;
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
    
    
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    int xsz=table[0].size();
    int ysz=table.size();
    
    // 1. 모양 적출하기 
    for(int i=0;i<table.size();i++){
        for(int j=0;j<table[i].size();j++){
            if(table[i][j] && !vis[i][j]){
                queue<pair<int,int>> q;
                vector<pair<int,int>> vt;
                q.push({i,j});
                vis[i][j]=1;
                vt.push_back({i,j});
                
                while(q.size()){
                    auto cur=q.front();
                    q.pop();
                    
                    for(int k=0;k<4;k++){
                        int nx=cur.second+dx[k];
                        int ny=cur.first+dy[k];
                        
                        if(nx<0 || ny<0 || nx>=xsz || ny>=ysz) continue;
                        
                        if(table[ny][nx] && !vis[ny][nx]){
                            vis[ny][nx]=1;
                            q.push({ny,nx});
                            vt.push_back({ny,nx});
                        }
                    }
                    
                }
                
                v.push_back(vt);
            }
        }
    }
    
    // 1.1 상대적 위치 구함 
    sort(v.begin(),v.end());
    
    for(auto& vt : v){
        sort(vt.begin(),vt.end());
    }
    
    for(auto& vt : v){
        for(int i=1;i<vt.size();i++){
            vt[i]={vt[i].first-vt[0].first,vt[i].second-vt[0].second};
        }
        vt[0]={0,0};
    }
    
    // 2. 각 좌표에 대해서 game_board 4번 돌려서 확인 
    vector<vector<int>> gb=game_board;
    for(auto& vt : v){
        
        for(int i=0;i<4;i++){
            gb=rotate(gb);
            
            if(isValid(vt,gb)){
                answer+=vt.size();
                break;
            }
        }
    }
    
    return answer;
}