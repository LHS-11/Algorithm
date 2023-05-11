import java.util.*;
import java.io.*;

/*
BFS 이용해서 각 영역의 수를 구한 뒤 오름차순 정렬 
*/
public class Main
{
    static int[] dx={-1,0,1,0};
    static int[] dy={0,-1,0,1};

    static class Pair{
        int first;
        int second;

        Pair(int first,int second){
            this.first=first;
            this.second=second;
        }
    }

    public static void main(String args[]) throws IOException
    {

        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());

        char[][] arr=new char[n][n];
        for(int i=0;i<n;i++){
            String str=br.readLine();
            for(int j=0;j<str.length();j++){
                arr[i][j]=str.charAt(j);
            }
        }
        
        Queue<Pair> q=new LinkedList<>();
        int[][] vis=new int[n][n];
        List<Integer> ans=new ArrayList<>();
        int sz=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && arr[i][j]=='1'){
                    int cnt=0;
                    q.add(new Pair(i,j));
                    vis[i][j]=1;
                    sz++;
                    while(!q.isEmpty()){
                        Pair cur=q.poll();
                        cnt++;

                        for(int k=0;k<4;k++){
                            int nx=cur.second+dx[k];
                            int ny=cur.first+dy[k];

                            if(nx<0 || ny<0 || nx>=n || ny>= n) continue;

                            if(vis[ny][nx]>0) continue;

                            if(arr[ny][nx]=='1'){
                                q.add(new Pair(ny,nx));
                                vis[ny][nx]=1;
                            }
                        }
                    }
                    ans.add(cnt);
                }
            }
        }

        Collections.sort(ans);
        System.out.println(sz);
        ans.stream().forEach(System.out::println);
    }
}