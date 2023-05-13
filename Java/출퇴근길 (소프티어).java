import java.util.*;
import java.io.*;


public class Main
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String[] s=br.readLine().split(" ");
        int n=Integer.parseInt(s[0]);
        int m=Integer.parseInt(s[1]);

        List<Integer>[] node=new ArrayList[n+1];
        List<Integer>[] nodeR=new ArrayList[n+1];
        for(int i=1;i<=n;i++) {
            node[i]=new ArrayList<>();
            nodeR[i]=new ArrayList<>();

        }

        for(int i=0;i<m;i++){
            String[] st=br.readLine().split(" ");
            int a=Integer.parseInt(st[0]);
            int b=Integer.parseInt(st[1]);
            node[a].add(b);
            nodeR[b].add(a);
        }

        String[] str=br.readLine().split(" ");
        int S=Integer.parseInt(str[0]);
        int T=Integer.parseInt(str[1]);

        int[] vis=new int[n+1]; // S-> 중간지점
        vis[T]=1;
        bfs(S,node,vis);  
        int[] vis1=new int[n+1]; // T -> 중간지점
        vis1[S]=1;
        bfs(T,node,vis1);
        int[] vis2=new int[n+1]; // 역방향 간선 그래프에서 S-> 중간지점 (중간지점 -> S)
        bfs(S,nodeR,vis2);
        int[] vis3=new int[n+1]; // 역방향 간선 그래프에서 T-> 중간지점 (중간지점 -> T)
        bfs(T,nodeR,vis3);

        int ans=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==1 && vis1[i]==1 && vis2[i]==1 && vis3[i]==1){
                ans++;
            }
        }

        System.out.println(ans-2);


    }

    static void bfs(int now,List<Integer>[] node,int[] vis){
        Queue<Integer> q=new LinkedList<>();
        q.add(now);
        vis[now]=1;

        while(!q.isEmpty()){
            int cur=q.poll();

            for(int i=0;i<node[cur].size();i++){
                int nxt=node[cur].get(i);
                if(vis[nxt]>0) continue;
                vis[nxt]=1;
                q.add(nxt);
            }
        }
    }
}