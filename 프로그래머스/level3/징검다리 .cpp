#include<bits/stdc++.h>
using namespace std;

int check(int k,vector<int>& r){
    
    int cnt=0;
    int prev=0;
    
    for(int i=1;i<r.size();i++){
        int t=r[i]-prev;
        if(t<k){
            cnt++;   
        }else prev=r[i];
    }
    return cnt;
}
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    
    sort(rocks.begin(),rocks.end());
    vector<int> rr={0};
    for(auto n : rocks) rr.push_back(n);
    rr.push_back(distance);

    int l=0,r=distance;
    
    while(l<=r){
        int m=(l+r)>>1;
        
        if(check(m,rr)>n){
            r=m-1;
        }else {
            l=m+1;
            answer=m;
        }
    }
    return answer;
}