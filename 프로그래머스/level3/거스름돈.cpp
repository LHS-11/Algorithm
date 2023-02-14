#include<bits/stdc++.h>
using namespace std;
int dp[100004];
int solution(int n, vector<int> money) {
    int answer = 0;
    dp[0]=1;
    sort(money.begin(),money.end());
    /*
    가장 작은 값만으로 만들 수 있는 경우의 수를 누적해서 dp로 구함
    */
    for(auto m : money){
        
        for(int i=1;i<=n;i++){
            if(i-m>=0){
                dp[i]+=dp[i-m];
            }
        }
        
    }
    
    
    return dp[n];
}