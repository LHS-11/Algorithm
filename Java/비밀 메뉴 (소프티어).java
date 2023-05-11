import java.util.*;
import java.io.*;

/*
완전탐색 문제 
*/
public class Main
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String[] str=br.readLine().split(" ");
        int[] a=new int[3];
        for(int i=0;i<3;i++){
            a[i]=Integer.parseInt(str[i]);
        }

        int[] sct=new int[a[0]];
        String[] strr= br.readLine().split(" ");
        for(int i=0;i<a[0];i++){
            sct[i]=Integer.parseInt(strr[i]);
        }

        int[] arr=new int[a[1]];
        String[] strrr= br.readLine().split(" ");
        for(int i=0;i<a[1];i++){
            arr[i]=Integer.parseInt(strrr[i]);
        }

        String ans="normal";
        for(int i=0;i<=a[1]-a[0];i++){
            boolean flag=false;

            for(int j=0;j<a[0];j++){
                if(arr[i+j]!=sct[j]){
                    flag=true;
                    break;
                }
            }

            if(!flag) ans="secret";
        }
        System.out.println(ans);
    }
}