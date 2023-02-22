#include<bits/stdc++.h>
using namespace std;

int MOD = 20170805;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int dp[504][504][2]={0};
    // fill 로 초기화를 시켰는데 왜 대체... 
    fill(&dp[0][0][0],&dp[0][0][0]+n*m*2,0);
    
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    // 위쪽에서 내려오는 dp 초기화
    for(int i=1;i<m;i++) {
        if(city_map[i][0]==1) break;
        dp[i][0][0]=1;
    }
    
    // 아래쪽에서 내려오는 dp 초기화
    for(int i=1;i<n;i++){
        if(city_map[0][i]==1) break;
        dp[0][i][1]=1;
    }
    
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){

            // 위쪽에서 온 경우
            if(city_map[i-1][j]!=1){
                dp[i][j][0]+=dp[i-1][j][0];
                if(city_map[i-1][j]!=2) dp[i][j][0]+=dp[i-1][j][1];
            }
            // 왼쪽에서 온 경우
            if(city_map[i][j-1]!=1){
                dp[i][j][1]+=dp[i][j-1][1];
                if(city_map[i][j-1]!=2) dp[i][j][1]+=dp[i][j-1][0];
            }
            dp[i][j][0]%=MOD;
            dp[i][j][1]%=MOD;
            
        }
    }
    
    return (dp[m-1][n-1][0]+dp[m-1][n-1][1])%MOD;
}
/*
BFS 풀이
#include<bits/stdc++.h>
using namespace std;
int MOD = 20170805;
int dx[2]={0,1}; // 아래, 오른쪽
int dy[2]={1,0};
int dp[504][504][2];
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    queue<tuple<int,int,int,int>> q; // y,x,dir,dp 값
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<2;k++) dp[i][j][k]=0;
        }
    }
    
    for(int i=0;i<2;i++) dp[0][0][i]=1;
    
    q.push({0,0,0,1});
    
    while(q.size()){
        int x,y,dir,v;
        tie(y,x,dir,v)=q.front();
        q.pop();
        
        if(dp[y][x][dir]!=v) continue;
        
        for(int i=0;i<2;i++){ // 아래, 오른쪽
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0 || ny<0 || nx>=n || ny >= m) continue;
            if(city_map[ny][nx] !=1){
                if(city_map[y][x]==2 && dir!=i) continue;
                dp[ny][nx][i]+=dp[y][x][dir]%MOD;
                q.push({ny,nx,i,dp[ny][nx][i]});
            }
        }
    }
    
    return (dp[m-1][n-1][0]+dp[m-1][n-1][1])%MOD;
}
*/