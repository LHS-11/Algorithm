#include<bits/stdc++.h>
using namespace std;
int answer=INT_MAX;
vector<string> mrl;
void go(int sel,int dcnt,int icnt,int scnt, int idx,int ans){
    
    if(idx>=mrl.size()) {
        answer=min(answer,ans);
        return;
    }
    
    int sum=0;
    for(int i=idx;i<idx+5;i++){
        if(i>=mrl.size()) break;
        if(sel==0){
           sum+=1;
        }else if(sel==1){
            if(mrl[i]=="diamond") sum+=5;
            else sum+=1;
        }else{
            if(mrl[i]=="diamond") sum+=25;
            else if(mrl[i]=="iron") sum+=5;
            else sum+=1;
        }
    }
    
    if(idx>=mrl.size() || (!dcnt && !icnt && !scnt)){
        answer=min(answer,ans+sum);
        return;
    }
    
    if(dcnt) go(0,dcnt-1,icnt,scnt,idx+5,ans+sum);
    if(icnt) go(1,dcnt,icnt-1,scnt,idx+5,ans+sum);
    if(scnt) go(2,dcnt,icnt,scnt-1,idx+5,ans+sum);
}
int solution(vector<int> picks, vector<string> minerals) {
    mrl=minerals;
    int dcnt=picks[0];
    int icnt=picks[1];
    int scnt=picks[2];
    
    if(dcnt) go(0,dcnt-1,icnt,scnt,0,0);
    if(icnt) go(1,dcnt,icnt-1,scnt,0,0);
    if(scnt) go(2,dcnt,icnt,scnt-1,0,0);
    return answer;
}
