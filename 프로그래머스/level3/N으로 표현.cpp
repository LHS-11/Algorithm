#include<bits/stdc++.h>
using namespace std;
set<int>dp[10];
int makeNum(int x,int N){
    
    int sum=0;
    for(int i=0;i<x;i++) sum+=(N*pow(10,i));
    return sum;
}
int solution(int N, int number) {
    
    dp[1].insert(N);
    
    if(N==number) return 1;
    
    for(int i=2;i<9;i++){
        
        dp[i].insert(makeNum(i,N));
        for(int j=1;j<i;j++){
            
            for(auto x : dp[j]){
                for(auto y : dp[i-j]){
                    int sum=x+y;
                    int minus=x-y;
                    int mlt=x*y;
                    int dv=x/y;
                    if(sum>0) dp[i].insert(sum);
                   if(minus>0) dp[i].insert(minus);
                   if(mlt>0) dp[i].insert(mlt);
                   if(dv>0) dp[i].insert(dv);
                }
            }
        }
        
        for(auto x : dp[i]){
            if(x==number) return i;
        }
    }
    
    
    return -1;
}