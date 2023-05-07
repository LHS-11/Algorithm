import java.util.*;
class Solution {
    
    static class Pair{
        int first;
        int second;
        
        public Pair(int first,int second){
            this.first=first;
            this.second=second;
        }
    }
    public int solution(int[][] jobs) {
        int answer = 0;
        
        int time=0;
        
        // Arrays.sort(jobs, (job1, job2) -> job1[0] - job2[0]);
        Comparator<int[]>cmp1=Comparator.comparing((int [] a)->a[0]).thenComparing(a->a[1]);
        Arrays.sort(jobs,cmp1);
        // Arrays.sort(jobs, new Comparator<>() {
        //     @Override
        //     public int compare(int[] job1, int[] job2) {
        //         return job1[0] - job2[0];
        //  }
        // });

        
        Comparator<Pair> cmp = Comparator.comparing((Pair p)->p.second).thenComparing(p->p.first);
        
        PriorityQueue<Pair> pq=new PriorityQueue<>(cmp);
        
        int idx=0;
        while(idx<jobs.length || !pq.isEmpty()){
            
            if(idx<jobs.length && jobs[idx][0]<=time){
                pq.add(new Pair(jobs[idx][0],jobs[idx][1]));
                idx++;
                continue;
            }
            
            if(!pq.isEmpty()){
                Pair cur=pq.poll();
                time+=cur.second;
                answer+=time-cur.first;
            }else{
                time=jobs[idx][0];
            }
        }
        
        return answer/jobs.length;
    }
}