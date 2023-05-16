/*
크기가 최대 20? => 완전탐색이겠구나? => 각 행과 열의 최대 갯수는 20 => 중복 순열? 20^20 절대 안됨
=> 순열? => 순서는 상관없이 선택만 하면 됨 => 각 행열을 선택 2^20 시간 충분 


*/
import java.util.*;
class Solution {
    
    static int n;
    static int m;
    
    public int solution(int[][] begin, int[][] target) {
        int answer = Integer.MAX_VALUE;
        
        n=begin.length;
        m=begin[0].length;
        int[][] arr=new int[n][m];
        
        int x=3;
        int y=(1<<1);
        
        System.out.println(x&y);
        
        for(int i=0;i<(1<<n+m);i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                arr[j]=Arrays.copyOf(begin[j],begin[j].length);
            }
            
            for(int j=0;j<n+m;j++){
                if((i & (1<<j))!=0){ // (i & (1<<j)) == 1 이건 i & (1<<j)은 1의 값을 가지는게 아니라 전체적으로 비트연산한 값이 나오기 때문에 틀림 
                    change(j,arr);
                    cnt++;
                }
            }
           
            if(check(arr,target)){
                answer=Math.min(answer,cnt);
            }
        }
        
        if(answer==Integer.MAX_VALUE){
            answer=-1;
        }
        
        return answer;
    }
    
    static void change(int k,int[][] arr){
        if(k<n){ // 행이 변화 
            for(int i=0;i<m;i++) arr[k][i]=(arr[k][i]+1)%2;
        }else{ // 열이 변화 
            for(int i=0;i<n;i++) arr[i][k-n]=(arr[i][k-n]+1)%2;
        }
    }
    
    static boolean check(int[][] arr,int[][] target){
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!=target[i][j]){
                    return false;
                }
            }
        }
        
        return true;
    }
}