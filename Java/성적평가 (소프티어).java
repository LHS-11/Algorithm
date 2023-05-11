import java.util.*;
import java.io.*;

/*
소프티어 성적 평가 
*/
public class Main
{

    static class Pair{
        int first;
        int second;

        Pair(int f,int s){
            this.first=f;
            this.second=s;
        }
    }
    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        // StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(br.readLine());

        List<Pair>[] a=new ArrayList[n+1];
        for(int i=0;i<=n;i++) a[i]=new ArrayList<>();
        List<Pair> b=new ArrayList<>();
        List<Pair> c=new ArrayList<>();
        List<Pair> d=new ArrayList<>();

        int[] sum=new int[n+1];
        for(int i=0;i<3;i++){
            String[] s=br.readLine().split(" ");
           
            for(int j=0;j<n;j++){
                a[i].add(new Pair(j,Integer.parseInt(s[j])));
                sum[j]+=Integer.parseInt(s[j]);
            }
        }

        for(int i=0;i<n;i++){
            a[3].add(new Pair(i,sum[i]));
        }

        Comparator<Pair> cmp=Comparator.comparing((Pair p)->p.second,Comparator.reverseOrder());
        for(int i=0;i<=3;i++){
            a[i].sort(cmp);
        }

        for(int i=0;i<4;i++){
            int rk=0,last=-1;
            int t=1;
            int[] rank=new int[n+1];
            for(Pair p : a[i]){
                if(last!=p.second){
                    rk+=t;
                    t=1;
                }else {
                    t++;
                }
                rank[p.first]=rk;
                last=p.second;
            }

            for(int j=0;j<n;j++){
                System.out.print(rank[j]+" ");
            }
            System.out.println();
        }


    }
}