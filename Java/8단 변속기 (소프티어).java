import java.util.*;
import java.io.*;


public class Main
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String[] str=br.readLine().split(" ");
        String s=String.join("",str);
        // int[] arr=new int[str.length];
        
        // for(int i=0;i<str.length;i++){
        //     arr[i]=Integer.parseInt(str[i]);
        // }
        
        String ans;
        if(s.equals("12345678")) ans="ascending"; 
        else if(s.equals("87654321")) ans="descending";
        else ans="mixed";
        
        System.out.println(ans);
    }
}