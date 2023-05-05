/*
일단 체크함수를 둬서 각 숫자마다 카운팅 
우선순위 큐를 두개 만듦
16 0
-5643 0
123 1 

최소힙
16,123

최대힙
123
*/
import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        
        Map<Integer,Integer> check=new HashMap<>();
        PriorityQueue<Integer> maxPq=new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> minPq=new PriorityQueue<>();
        
        
        for(String o : operations){
            if(o.charAt(0)=='I'){
                int num=Integer.parseInt(o.substring(2));
                
                maxPq.add(num);
                minPq.add(num);
                check.put(num,check.getOrDefault(num,0)+1);
            }else{
                if(o.charAt(2)=='-'){ // 최솟값 삭제
                    // int num=Integer.parseInt(o.substring(3));
                    
                    if(minPq.isEmpty()) continue;
                    int num = minPq.poll();
                    
                    check.put(num,check.get(num)-1);
                    
                }else{ // 최댓값 삭제 
                    
                    if(maxPq.isEmpty()) continue;
                    int num= maxPq.poll();
                    check.put(num,check.get(num)-1);
                }
                
                while(!maxPq.isEmpty() && check.get(maxPq.peek())==0){
                        maxPq.poll();
                }
                while(!minPq.isEmpty() && check.get(minPq.peek())==0){
                        minPq.poll();
                }
                
            }
        }
        
        if(minPq.isEmpty() && maxPq.isEmpty()){
            answer[0]=0;
            answer[1]=0;
        }else{
            answer[0]=maxPq.peek();
            answer[1]=minPq.peek();
            
        }
        
        return answer;
    }
}