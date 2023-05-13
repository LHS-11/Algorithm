import java.util.*;
import java.io.*;

/*
이름들을 입력 받고, 정렬 
 배열에 숫자 카운팅 (끝나는 시간은 카운팅 하지 않고, 다시 거기부터 시작)
*/
public class Main
{
    static class Pair{
        String first;
        String second;

        Pair(String first,String second){
            this.first=first;
            this.second=second;
        }
    }
    public static void main(String args[]) throws IOException
    {
        
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String[] str= br.readLine().split(" ");
        int n=Integer.parseInt(str[0]);
        int m=Integer.parseInt(str[1]);

        Map<String,Integer> mp=new TreeMap<>();
        int[][] cnt=new int[54][20];
        int idx=0;
        for(int i=0;i<n;i++){
            String s=br.readLine();
            mp.put(s,mp.getOrDefault(s,idx++));
        }

        for(int i=0;i<m;i++){
            String[] s=br.readLine().split(" ");
            String nme=s[0];
            int st=Integer.parseInt(s[1]);
            int en=Integer.parseInt(s[2]);
            for(int j=st;j<en;j++){
                cnt[mp.get(nme)][j]=1;
            }
        }

        // for(int i=9;i<=18;i++){
        //     System.out.print(cnt[1][i]+" ");
        // }
        // System.out.println();

        // Collections.sort(name);
        int idxx=0;
        for(String key : mp.keySet()){
            boolean flag=true;
            int val=mp.get(key);

            int cntt=0;
            List<Pair> lst=new ArrayList<>();
            int st=9,en=9;
        
            for(int i=9;i<=18;i++){
                
                if(cnt[val][i]==1 && !flag){
                    en=i;

                    if(st==en) continue; // 바로 자리가 있을 때 
                    // System.out.println(key+" "+st+" "+en);
                    cntt++;
                    if(st==9) lst.add(new Pair("09",String.valueOf(en)));
                    else lst.add(new Pair(String.valueOf(st),String.valueOf(en)));
                    flag=true;
                }else if(cnt[val][i]==0 && flag){
                    st=i;
                    flag=false;
                }
            }

            if(st<18) {
                if(st==9) lst.add(new Pair("09","18"));
                else lst.add(new Pair(String.valueOf(st),"18"));
                cntt++;
            }

            System.out.println("Room "+key+":");
            if(cntt==0) System.out.println("Not available");
            else System.out.println(cntt+" available:");
            for(Pair p : lst){
                System.out.println(p.first+"-"+p.second);
            }
            idxx++;
            if(idxx!=n) System.out.println("-----");
        }



    }
}