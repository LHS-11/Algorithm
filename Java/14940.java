import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    static int n;
    static int m;
    static int[][] vis=new int[1004][1004];

    static int[] dx={0,0,1,-1};
    static int[] dy={1,-1,0,0};

    static class Pair{
        int f;
        int s;

        Pair(int f,int s){
            this.f=f;
            this.s=s;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);

        int[][] arr=new int[n][m];
        Queue<Pair> q = new LinkedList<>();

        for(int i=0;i<n;i++){
            String[] s = br.readLine().split(" ");
            for(int j=0;j<m;j++){
                arr[i][j] = Integer.parseInt(s[j]);
                if(arr[i][j]==2) {
                    q.add(new Pair(i, j));
                    vis[i][j]=1;
                }else if(arr[i][j]==0){
                    vis[i][j]=1;
                }
            }
        }

        while(!q.isEmpty()){
            Pair cur = q.poll();

            for(int i=0;i<4;i++){
                int nx=cur.s+dx[i];
                int ny=cur.f+dy[i];

                if(nx<0 || ny<0 || nx>=m || ny>=n) continue;

                if(vis[ny][nx]>0) continue;
                if(arr[ny][nx]==1){
                    vis[ny][nx]=vis[cur.f][cur.s]+1;
                    q.add(new Pair(ny, nx));
                }
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                System.out.print((vis[i][j]-1)+" ");
            }
            System.out.println();
        }
    }
}
