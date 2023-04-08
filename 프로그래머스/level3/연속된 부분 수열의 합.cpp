#include <string>
#include <vector>
#include<iostream>
#include<tuple>
#include<algorithm>
using namespace std;
/*
연속된 부분 수열의 합이 k인 부분 수열중 가장 짧은 길이를 가지고 
먼저 나오는 부분 수열을 구하는 문제 
답은 부분 수열의 첫번째 인덱스와 마지막 인덱스만 담음 

딱 생각나는게 일단 누적합 부분합 

1 3 6 10 15 => 누적합에서
1 2 3 5 8 12 17 => 이분탐색

*/
int sum[1000004];
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    for(int i=0;i<sequence.size();i++){
        sum[i+1]+=sequence[i];
        sum[i+1]+=sum[i];
    }
    
    int l=0,r=sequence.size()-1;
    while(l<=r){
        int m=(l+r)>>1;
        
        if(sum[m]-k>=0){
            r=m-1;
        }else l=m+1;
    }
    
    vector<tuple<int,int,int>> v;
    //1 3 6 10 15 
    //l   m     r 
    //       l,m r
    //
    for(int i=0;i<sequence.size();i++){
        int l=0,r=sequence.size();
        while(l<=r){
            int m=(l+r)>>1;
        
            if(sum[m]-sum[i]>k){
                r=m-1;
            }else if(sum[m]-sum[i]==k){
                v.push_back({m-i,i+1,m});
                break;
            }
            else l=m+1;
        }    
    }
    sort(v.begin(),v.end());
    
    answer.push_back(get<1>(v[0])-1);
    answer.push_back(get<2>(v[0])-1);
    
    return answer;
}