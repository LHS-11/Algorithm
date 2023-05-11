import java.util.*;
import java.io.*;


public class Main
{

    private static final long MOD=1000000007;

    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String[] str=br.readLine().split(" ");
        long k=Long.parseLong(str[0]);
        long p=Long.parseLong(str[1]);
        long n=Long.parseLong(str[2]);

        long ans=k;
        while((n--)>0){
            ans=(ans*p%MOD);
        }
        System.out.println(ans);

    }
}