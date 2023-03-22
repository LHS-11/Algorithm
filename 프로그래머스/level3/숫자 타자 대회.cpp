#include <string>
#include <vector>
#include<string.h>
#include<iostream>
using namespace std;
int dis[10][10]={
    {1,7,6,7,5,4,5,3,2,3},
    {7,1,2,4,2,3,5,4,5,6},
    {6,2,1,2,3,2,3,5,4,5},
    {7,4,2,1,5,3,2,6,5,4},
    {5,2,3,5,1,2,4,2,3,5},
    {4,3,2,3,2,1,2,3,2,3},
    {5,5,3,2,4,2,1,5,3,2},
    {3,4,5,6,2,3,5,1,2,4},
    {2,5,4,5,3,2,3,2,1,2},
    {3,6,5,4,5,3,2,4,2,1} 
};
int dp[10][10][100004];
string num;
int go(int left,int right,int idx){
    
    if(idx==num.size()){
        return 0;
    }
    
    int& rst=dp[left][right][idx];
    
    if(rst!=-1){
        return rst;
    }
    
    int nxt=num[idx]-'0';
    
    if(left==nxt || right==nxt) return rst=1+go(left,right,idx+1);// 이걸 안하면 두손이 같은 자판에 올라갈 수 있기 때문에 해야 함 
    // "151506" 원래 답은 15인데 
    // 4,6 -> 1,4 -> 1,5 -> 1,5 -> 5,5 -> 0,5 -> 0,6
    //  2 + 2 + 1 + 3 +4 + 2 => 14 
    return rst=min(go(nxt,right,idx+1)+dis[left][nxt],go(left,nxt,idx+1)+dis[right][nxt]);
    
}
int solution(string numbers) {
    num=numbers;
    memset(dp,-1,sizeof(dp));
    
    return go(4,6,0);
}