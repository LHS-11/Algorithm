#include<bits/stdc++.h>
using namespace std;
int dp1[1000004];
int dp2[1000004];
int solution(vector<int> money) {
    int answer = 0;
    
    vector<int> t1,t2;
    
    t1.push_back(0);
    t2.push_back(0);
    
    for(int i=0;i<money.size()-1;i++) t1.push_back(money[i]);
    for(int i=1;i<money.size();i++) t2.push_back(money[i]);
    
    dp1[1]=t1[1];
    dp2[1]=t2[1];
    // 0 1 2 3
    for(int i=2;i<money.size();i++){
        dp1[i]=max(dp1[i-2]+t1[i],dp1[i-1]);
        dp2[i]=max(dp2[i-2]+t2[i],dp2[i-1]);
    }
    
    return max(dp1[t1.size()-1],dp2[t2.size()-1]);
}