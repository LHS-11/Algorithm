/*
0 1 =>[0 0] [1 1] / => m[0][0] * m[0][1] * m[1][1]
1 2 =>[1 1] [2 2] / => m[1][0] * m[1][1] * m[2][1]
0 2 =>[0 0] [1 2] / => dp[0][0] + dp[1][2] + m[0][0] * m[0][1] * m[2][1] 
0 2 =>[0 1] [2 2] / => dp[0][1] + dp[2][2] + m[0][0] * m[1][1] * m[2][1]
*/
class Solution {
    public int solution(int[][] m) {
        int answer = 0;
        
        
        int[][] dp=new int[204][204];
        int sz=m.length;
        
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                dp[i][j]=(int)1e9;
            }
        }
        
        for(int i=0;i<sz;i++) dp[i][i]=0;
        
        
        for(int k=1;k<sz;k++){ // 범위 
            for(int i=0;i<sz-k;i++){ // 처음 시작 
                for(int j=i;j<i+k;j++){ // 결합 
                    dp[i][i+k]=Math.min(dp[i][i+k],dp[i][j]+dp[j+1][i+k]+m[i][0]*m[j][1]*m[i+k][1]);
                   
                }
            }
        }
        
        answer=dp[0][sz-1];
        
        
        return answer;
    }
}