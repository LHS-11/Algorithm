class Solution {
    public int solution(int n, int[][] results) {
        int answer = 0;
        
        int[][] check=new int[n+1][n+1];
        
        for(int i=0;i<results.length;i++){
            check[results[i][0]][results[i][1]]=1;
            // check[results[i][1]][results[i][0]]=1;
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(j!=k && check[j][i]>0 && check[i][k]>0){
                        check[j][k]=1;
                        // check[k][j]=1;
                    }
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            int flag=0;
            
            for(int j=1;j<=n;j++){
                if(i!=j && check[i][j]==0 && check[j][i]==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0) answer++;
        }
        
        
        return answer;
    }
}