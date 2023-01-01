#include<bits/stdc++.h>
using namespace std;

int solution(int storey) {
    int answer = 0;

    // 해당 자릿수가 5일때 올려야 할지 내려야 할지를 처리해줘야 하는 문제
    while(storey){
        int c=storey%10;
        if(c>5){
            answer+=10-c;
            storey+=10;
        }
        else{
            answer+=c;
            if(c==5 && (storey/10)%10>=5){
                storey+=10;
            }
        }
        storey/=10;
    }
    
    return answer;
}