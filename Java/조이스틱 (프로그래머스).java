/*
커서 4개를 구현 
위아래 -> 알파벳 선택 밑으로 하는 것이 더 가까운지, 앞으로 누르는 것이 더 가까운지 판단해야함
왼쪽오른쪽 -> A가 얼마나 존재하는가 중간에 

아래쪽으로 이동시 'Z'-char+1 횟수 
위쪽 이동시 char-'A' 횟수 

1. 앞에서부터 뒤로 이동할 경우 
2. 앞에서부터 뒤로 이동했다가, 다시 뒤쪽으로 이동하는 경우 
*/
class Solution {
    
    int select(char c){
        return Math.min('Z'-c+1,c-'A');
    }
    
    
    public int solution(String name) {
        int answer = 0;
        
        String str="";
        
        int dis=name.length()-1;
        for(int i=0;i<name.length();i++){
            
            answer+=select(name.charAt(i));
            
            int idx=i+1;
            
            while(idx<name.length() && name.charAt(idx)=='A'){
                idx++;
            }
            
            int cnt=Math.min(2*i+name.length()-idx,i+2*(name.length()-idx));
            dis=Math.min(dis,cnt);
            
        }
        
        answer+=dis;
        
        return answer;
    }
}