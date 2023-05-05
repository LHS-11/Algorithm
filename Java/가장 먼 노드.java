/*
BFS 돌려서 모든 노드의 거리를 기록하고,
for문 돌려서 각 노드의 최댓값을 카운팅 
*/
import java.util.*;
class Solution {
    
    private static final int INF=20004;
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        int mx=0;
        
        
        
        // 1. 그래프 만들기
        List<Integer>[] node=new ArrayList[INF];
        
        for(int i=0;i<INF;i++){
            node[i]=new ArrayList<>();
        }
        
        for(int i=0;i<edge.length;i++){
            node[edge[i][0]].add(edge[i][1]);
            node[edge[i][1]].add(edge[i][0]);
        }
        
        //2. BFS 
        int[] vis=new int[INF];
        Queue<Integer> q=new LinkedList<>();
        vis[1]=1;
        q.add(1);
        
        while(!q.isEmpty()){
            int cur=q.poll();
            
            mx=Math.max(vis[cur],mx);
            
            for(int i=0;i<node[cur].size();i++){
                int nxt=node[cur].get(i);
                if(vis[nxt]>0) continue;
                vis[nxt]=vis[cur]+1;
                q.add(nxt);
            }
        }
        
        for(int i=1;i<INF;i++){
            if(mx==vis[i]){
                answer++;
            }
        }
        
        
        
        return answer;
    }
}