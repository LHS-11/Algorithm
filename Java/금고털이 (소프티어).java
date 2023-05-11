import java.util.*;
import java.io.*;

/*
가장 큰 무게를 내림차순으로 정렬 후, for문을 돌면서 무게 채우기 
*/
public class Main
{
    static class Pair{
        int first;
        int second;

        public Pair(int first,int second){
            this.first=first;
            this.second=second;
        }
    }
    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        
        int w=Integer.parseInt(st.nextToken());
        int n=Integer.parseInt(st.nextToken());

        int[][] bag=new int[n][2];
        List<Pair> lst=new ArrayList<>();
        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            lst.add(new Pair(a,b));
        }

        Comparator<Pair> cmp=Comparator.comparing((Pair p)->p.second,Comparator.reverseOrder())
        .thenComparing(p->p.first);

        lst.sort(cmp);
        // Collections.sort(lst,cmp);

        int ans=0;
        for(int i=0;i<n;i++){
            Pair cur=lst.get(i);

            if(w<=0) break; // 배낭에 꽉 찼을 때 탈출

            if(cur.first>=w){ // 현재 배낭보다 무게가 클 때 (자르면 됨) 
                ans+=w*cur.second;
                w=0;
            }else{
                ans+=cur.first*cur.second;
                w-=cur.first;
            }
        }

        System.out.println(ans);

    }
}