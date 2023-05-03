/*
number는 백만이하의 숫자이기 때문에, 완탐은 불가능 ! 
*/
import java.util.*;
class Solution {
    public String solution(String number, int k) {
        String answer = "";
        
        
        int idx=0;
        for(int i=0;i<number.length()-k;i++){
            char mx='0';
            
            for(int j=idx;j<=i+k;j++){
                if(number.charAt(j)>mx){
                    idx=j+1;
                    mx=number.charAt(j);
                    if(mx=='9') break;
                }
                
            }
            
            answer+=mx;
        }
        
        
        return answer;
    }
}