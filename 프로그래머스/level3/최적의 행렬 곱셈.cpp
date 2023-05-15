#include<bits/stdc++.h>
using namespace std;
/*
5 x 3 x 10 x 6

5 x 3 x 10
5 x 10 x 6
150 + 300

3 x 10 x 6
5 x 3 x 6
180 + 90
*/
int dp[204][204];
int chk[204][204];
int solution(vector<vector<int>> m) {
    int answer = 0;

    int size=m.size();

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            dp[i][j]=1e9;
        }
    }


    for(int i=0;i<m.size();i++) dp[i][i]=0;

    for(int i=1;i<m.size();i++){ // m.size()=3 

        for(int j=0;j<m.size()-i;j++){

            for(int k=j;k<j+i;k++){
                dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+m[j][0]*m[k][1]*m[i+j][1]);
            }
        }
    }

    cout<<dp[0][2]<<endl;

    return dp[0][size-1];
}