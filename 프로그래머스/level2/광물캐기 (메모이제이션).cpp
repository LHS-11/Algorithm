#include <string>
#include <vector>
#include<string.h>
#include<climits>
using namespace std;
vector<string>mrl;
int dp[54][6][6][6];
int go(int idx,int dcnt,int icnt,int scnt){
    
    if(idx>=mrl.size() || (!dcnt && !icnt && !scnt)) return 0;
    
    int& rst=dp[idx][dcnt][icnt][scnt];
    
    if(rst!=-1){
        return rst;
    }
    
    rst=INT_MAX;
    int sum=0;
    if(dcnt){
        for(int i=idx;i<idx+5;i++){
            if(i>=mrl.size()) break;
            sum+=1;
        }
        rst=min(rst,go(idx+5,dcnt-1,icnt,scnt)+sum);
    }
    if(icnt){
        sum=0;
        for(int i=idx;i<idx+5;i++){
            if(i>=mrl.size()) break;
            if(mrl[i]=="diamond"){
                sum+=5;
            }else sum+=1;
        }
        rst=min(rst,go(idx+5,dcnt,icnt-1,scnt)+sum);
        
    }
    if(scnt){
        sum=0;
        for(int i=idx;i<idx+5;i++){
            if(i>=mrl.size()) break;
            if(mrl[i]=="diamond"){
                sum+=25;
            }else if(mrl[i]=="iron"){
                sum+=5;
            }else sum+=1;
        }
        rst=min(rst,go(idx+5,dcnt,icnt,scnt-1)+sum);
    }
    return rst;
}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    mrl=minerals;
    memset(dp,-1,sizeof(dp));
    
    return go(0,picks[0],picks[1],picks[2]);
}