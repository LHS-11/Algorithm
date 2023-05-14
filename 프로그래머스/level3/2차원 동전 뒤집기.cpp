#include<bits/stdc++.h>
using namespace std;
/*
완전탐색 문제 
결국 순서는 상관없는 조합의 문제 
처음 나의 생각은 어.. 행 열 여러번 곱할 수 있는거 아닌가? 라고 생각을 해서 그럼 20^20 이건 말이 안돼
-> 무조건 완탐 문제야 -> 각 행열이 한번씩만 나오고 조합 문제가 아닐까? 생각 
*/
int ans=INT_MAX,n,m;
int arr[14][14];
void change(int tmp[][14] ,int k){
    
    if(k<n){ // 행 뒤집기 
        for(int i=0;i<m;i++){
            tmp[k][i]=!tmp[k][i];
        }
    }else{ // 열 뒤집기 
        for(int i=0;i<n;i++){
            tmp[i][k-n]=!tmp[i][k-n];
        }
    }
}
void go(int k,vector<vector<int>>target){

    int tmp[n][14],cnt=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j]=arr[i][j];
        }
    }
    
    vector<int> v;
    for(int i=0;i<n+m;i++){
        if(k & (1<<i)){
            v.push_back(i);
            cnt++;
        }
    }
    
    for(auto& c : v){
        change(tmp,c);
    }
    
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp[i][j] !=target[i][j]){
                flag=1;
                break;
            }
            if(flag) break;
        }
    }
    if(!flag) ans=min(ans,cnt);

}
int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 0;
    
    n=beginning.size();
    m=beginning[0].size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=beginning[i][j];
        }
    }
    
    for(int i=0;i<(1<<(n+m));i++){ // 모든 경우의 수 탐색 
        go(i,target);
    }
    
    if(ans==INT_MAX) ans=-1;
    
    return ans;
}