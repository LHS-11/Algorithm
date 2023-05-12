import java.util.*;
import java.io.*;

/*
완전 분할 or 규칙 찾아서 dp 
*/
public class Main
{
    public static void main(String args[])
    {
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();

        int[] dp=new int[17];

        dp[2]=9;
        // dp[3]=25;

        for(int i=3;i<=16;i++){
           int x=(int)Math.pow(4,i-2); // 이전의 정사각형의 갯수 
            int cur=(int)Math.pow(2,i-2); // 현재 정사각형의 길이 

            dp[i]+=dp[i-1]+x*5-((cur-1)*2 *cur );
        }

    System.out.println(dp[n+1]);

    }


}