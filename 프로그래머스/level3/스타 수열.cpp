#include <string>
#include <vector>
using namespace std;
/*
부분 수열 -> 원래 순서를 유지하여 얻을 수 있는 새로운 수열
스타 수열은 2개씩 집합으로 나눴을 때 각각의 집합의 교집합의 원소의 개수가 1개 이상
못풀었던 이유
=> 사고가 부족함 (교집합의 원소를 먼저 구해서 해볼 생각을 못함...)
조건은 총 3가지
1. 스타 수열은 무조건 짝수개의 부분수열 
2. 스타 수열을 2개씩 집합으로 나눴을 때 교집합의 원소가 1개 이상
3. 2개씩 집합으로 나눴을 때, 같은 집합에 있는 값들이 같으면 안됨 

=> 여기서 내가 생각해야 하는건 교집합의 원소를 찾으면 되지 않을까? 
=> 교집합의 원소만 정해두면, 양 옆만 확인하면서 진행하면 됨 
=> 교집합을 카운팅 배열에 넣어두고 최악의 경우는 길이가 50만일때가 아님
=> 완탐을 해도 시간 초과가 안나는 이유, 처음에 answer을 갱신하고 answer보다 cnt 값이 같거나 적으면 continue를 통해 바로 넘겨버림 
*/
int cnt[500004];
int solution(vector<int> a) {
    int answer = 0;
    
    for(auto x : a){
        cnt[x]++;
    }
    
    for(int i=0;i<a.size();i++){
        if(answer>=cnt[i]*2) continue;
        
        int cnt=0;
        for(int j=0;j<a.size()-1;j++){
            
            if((a[j]==i ||a[j+1]==i) && a[j]!=a[j+1]){
                cnt++;
                j++;
            }
        }
        answer=max(answer,cnt*2);
    
    }
    
    
    return answer;
}