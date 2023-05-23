class Solution {
    /*
   100 2 3 400 500
   
   100 2 3 400 => dp1[0]=100, dp1[1]=100, dp1[2]=max(dp1[0]+3,dp1[1])=max(103,100)=103
   dp1[3]=max(dp1[1]+400,dp1[2])=max(500,103)
   2 3 400 500 
   */
    static final int MAX=1000004;
    public int solution(int[] money) {
        int answer = 0;
        
        int dp1[]=new int[MAX];
        int dp2[]=new int[MAX];
        
        dp1[0]=money[0];
        dp1[1]=Math.max(dp1[0],money[1]);
        for(int i=2;i<money.length-1;i++){
            dp1[i]=Math.max(dp1[i-1],dp1[i-2]+money[i]);
        }
        
        dp2[0]=money[1];
        dp2[1]=Math.max(dp2[0],money[2]);
        for(int i=3;i<money.length;i++){
            dp2[i-1]=Math.max(dp2[i-2],dp2[i-3]+money[i]);
        }
        
        return Math.max(dp1[money.length-2],dp2[money.length-2]);
    }
}