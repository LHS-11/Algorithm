#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
s<=x<=e 사이에서 x가 구구단에서 나온 횟수의 최댓값들중에 최소인 값을 구하는 문제 
8 => 1 2 4 8
6 => 1 2 3 6 
4 => 1 2 4
2 => 1 2 

1 2 2 2 2 3 4 4
1 2 3 5 7 4 6 8

*/
int cnt[5000004];
int dp[5000004];
const int sz=5000000;
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    
    for (int i = 1; i <= e; i++) {
        for (int j = 1; j <= e / i; j++) {
            cnt[i * j]++;
        }
    }
    
    int idx=0,mxCnt=0;
    for(int i=e;i>=1;i--){
        if(cnt[i]>=mxCnt){
            mxCnt=cnt[i];
            idx=i;
        }
        dp[i]=idx;
    }
    
    for(auto s : starts){
        answer.push_back(dp[s]);
    }
    
    return answer;
}