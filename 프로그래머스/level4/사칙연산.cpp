#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int mxdp[204][204];
int mndp[204][204];
int solution(vector<string> arr)
{
    int answer = -1;
    
    vector<string> oper;
    vector<int> num;
    
    for(int i=0;i<arr.size();i++){
        if(i%2==0) num.push_back(stoi(arr[i]));
        else oper.push_back(arr[i]);
    }
    
    fill(&mxdp[0][0],&mxdp[0][0]+204*204,-INF);
    fill(&mndp[0][0],&mndp[0][0]+204*204,INF);
    
    
    for(int i=0;i<num.size();i++){
        mxdp[i][i]=num[i];
        mndp[i][i]=num[i];
    }
    
    for(int i=1;i<=num.size();i++){ // 1 , 2 , 3 , 4 
        
        for(int j=0;j<num.size()-i;j++){ // [0][1]=
            
            for(int k=j;k<j+i;k++){
                
                if(oper[k]=="+"){
                    mxdp[j][i+j]=max(mxdp[j][i+j],mxdp[j][k]+mxdp[k+1][i+j]);
                    mndp[j][i+j]=min(mndp[j][i+j],mndp[j][k]+mndp[k+1][i+j]);
                }else{
                    mxdp[j][i+j]=max(mxdp[j][i+j],mxdp[j][k]-mndp[k+1][i+j]);
                    mndp[j][i+j]=min(mndp[j][i+j],mndp[j][k]-mxdp[k+1][i+j]);
                }
            }
            
        }
        
    }
    
    
    return mxdp[0][num.size()-1];
}