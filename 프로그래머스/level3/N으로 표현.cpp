#include<bits/stdc++.h>
using namespace std;
vector<int>dp[10];
int makeNum(int x,int N){
    
    int sum=0;
    for(int i=0;i<x;i++) sum+=(N*pow(10,i));
    return sum;
}
int solution(int N, int number) {
    
    dp[1].push_back(N);
    
    if(N==number) return 1;
    
    for(int i=2;i<9;i++){
        
        dp[i].push_back(makeNum(i,N));
        for(int j=1;j<i;j++){
            for(int k=0;k<dp[j].size();k++){
               for(int x=0;x<dp[i-j].size();x++){
                   int sum=dp[j][k]+dp[i-j][x];
                   int minus=dp[j][k]-dp[i-j][x];
                   int mlt=dp[j][k]*dp[i-j][x];
                   int dv=dp[j][k]/dp[i-j][x];
                   
                   if(sum>0) dp[i].push_back(sum);
                   if(minus>0) dp[i].push_back(minus);
                   if(mlt>0) dp[i].push_back(mlt);
                   if(dv>0) dp[i].push_back(dv);
               }
            }
            // for(auto x : dp[j]){
            //     for(auto y : dp[i-j]){
            //         int sum=x+y;
            //         int minus=x-y;
            //         int mlt=x*y;
            //         int dv=x/y;
            //         if(sum>0) dp[i].push_back(sum);
            //        if(minus>0) dp[i].push_back(minus);
            //        if(mlt>0) dp[i].push_back(mlt);
            //        if(dv>0) dp[i].push_back(dv);
            //     }
            // }
        }
        
        for(int x=0;x<dp[i].size();x++){
            if(dp[i][x]==number) return i;
        }
    }
    
    
    return -1;
}