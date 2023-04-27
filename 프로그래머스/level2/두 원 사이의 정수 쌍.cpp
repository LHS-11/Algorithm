#include <string>
#include <vector>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
/*
백만이면 완전탐색 불가능;
최소 O(nlogn)의 시간복잡도를 가져야 함 

x^2+y^2=r^2
x>=sqrt(r1^2-y^2) x<=sqrt(r1^2-y^2) 
x<=sqrt(r2^2-y^2) x>=sqrt(r2^2-y^2)
범위를 잘 생각하자... (그냥 계산 했을때, int형을 넘기면 에러가 뜸.. 앞에 long long을 붙이던가 아니면 아예
변수를 만들어서 빼자... )
*/
long long solution(int r1, int r2) {
    long long answer = 0;
    for(long long i=1;i<=r2;i++){
        
        long long y1=max((long long)0,(long long)ceil(sqrt((long long)r1*r1-(long long)i*i)));
        long long y2=floor(sqrt((long long)r2*r2-(long long)i*i));
        answer+=(y2-y1+1);
    }
    return (long long)answer*4;
}