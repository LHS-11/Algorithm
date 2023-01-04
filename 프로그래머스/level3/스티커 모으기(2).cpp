#include<bits/stdc++.h>
using namespace std;
int dp1[100004];
int dp2[100004];
int solution(vector<int> sticker)
{
    int answer =0;
    
    dp1[0]=sticker[0];
    for(int i=1;i<sticker.size()-1;i++){
        if(i==1) dp1[i]=max(sticker[i],sticker[i-1]);
        else dp1[i]=max(dp1[i-1],dp1[i-2]+sticker[i]);
    }
    answer=max(answer,dp1[sticker.size()-2]);
    

    if(sticker.size()!=1){
    dp2[1]=sticker[1];
    for(int i=2;i<sticker.size();i++){
        if(i==2) dp2[i]=max(sticker[i],sticker[i-1]);
        else dp2[i]=max(dp2[i-1],dp2[i-2]+sticker[i]);        
    }
    answer=max(answer,dp2[sticker.size()-1]);
    }else return sticker[0];

    return answer;
}