#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    
    int sz=cores.size();
    if(n<sz){
        return n;
    }
    
    int l=0;
    int r=1e7;
    while(l<=r){
        int m=(l+r)>>1;
        
        int sum=sz;
        int now=0;
        for(auto c : cores){
            sum+=m/c;
        }
        
        for(auto c : cores){
            if(m%c==0){
                sum--;
                now++;
            }
        }
        
        if(sum>=n){
            r=m-1;
        }else if(sum+now<n){
            l=m+1;
        }else{
            int cnt=0;
            for(int i=0;i<sz;i++){
                if(m%cores[i]==0) cnt++;
                if(cnt+sum==n){
                    return i+1;
                }
            }
    
        }
        
    }
    return answer;
}