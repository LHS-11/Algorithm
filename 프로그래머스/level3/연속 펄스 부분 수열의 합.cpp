#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[500004][2];
long long solution(vector<int> sequence) {
    long long answer = 0;
    
    dp[0][0]=sequence[0];
    dp[0][1]=-sequence[0];
    
    for(int i=1;i<sequence.size();i++){
        int x=(i%2==0 ? 1 : -1);
        dp[i][0]=max((ll)x*sequence[i],(ll)x*sequence[i]+dp[i-1][0]);
        dp[i][1]=max((ll)-x*sequence[i],(ll)-x*sequence[i]+dp[i-1][1]);
    }
    
    for(int i=0;i<sequence.size();i++){
        answer=max(dp[i][0],answer);
        answer=max(dp[i][1],answer);
    }
    return answer;
}
/*
// 카데인 알고리즘 O(n)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[500004][2];
long long solution(vector<int> sequence) {
    long long answer = 0;
    
    // 1. {1,-1,1,-1,....}
    // 2. {-1,1,-1,1,....}
    for(int i=0;i<sequence.size();i++){
        if(i%2!=0){ // 홀수 
            dp[i][0]=sequence[i];
            dp[i][1]=-sequence[i];
        }else{ // 짝수
            dp[i][0]=-sequence[i];
            dp[i][1]=sequence[i];
        }
    }
    
    ll cur=0;
    ll sum=dp[0][0];
    for(int i=0;i<sequence.size();i++){
        cur+=dp[i][0];
        sum=max(sum,cur);
        cur=max(cur,(ll) 0);
    }
    
    cur=0;
    ll sum1=dp[0][1];
    for(int i=0;i<sequence.size();i++){
        cur+=dp[i][1];
        sum=max(sum,cur);
        cur=max(cur,(ll) 0);
    }
    
    answer=max(sum,sum1);
    return answer;
}
*/