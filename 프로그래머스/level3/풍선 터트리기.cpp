#include<bits/stdc++.h>
using namespace std;
/*
1. 임의의 인접한 두 풍선을 고른 뒤, 두 풍선 중 하나를 터트립니다.
2. 이때 더 작은 풍선을 터트리는 경우는 하나만 가능하고, 그 이후에는 두 풍선을 고른 뒤 번호가 더 큰 풍선만을 터트릴 수 있다.
*/
int solution(vector<int> a) {
    int answer = 0;
    // 해당 값의 왼쪽 그룹과 오른쪽 그룹의 최솟값과 비교
    // 해당 값과 비교 했을때 그 해당 값이 가장 작거나 두번째로 작으면 터트릴 수 있음
    // 최소 힙을 두개 만들어서 (왼쪽, 오른쪽) 각 그룹 중에 아무 그룹이나 비었을 때는 체크 
    // 왼쪽, 해당 값, 오른쪽을 비교해서 두번째로 작거나 가장 작은 값이면 가능하다
    
//     priority_queue<int,vector<int>,greater<int>> lpq;
//     priority_queue<int,vector<int>,greater<int>> rpq;
//     map<int,int> mp;
    
//     for(auto n : a) rpq.push(n);
    
//     for(int i=0;i<a.size();i++){
       
//         if(lpq.empty() || rpq.empty()) answer++;
//         else{
            
//             if(rpq.top()==a[i]){
//             rpq.pop(); 
//             }
        
//             // while(mp[rpq.top()]){
//                 // rpq.pop();
//             // }    
            
//             int l=lpq.top();
//             int r=rpq.top();
//             if(a[i]<l || a[i]<r) answer++;
//         }
        
//         lpq.push(a[i]);
//         mp[a[i]]=1;
//     }
    
    vector<int> l(a.size());
    vector<int> r(a.size());
    
    l[0]=a[0];
    r[a.size()-1]=a[a.size()-1];
    for(int i=1;i<a.size();i++){
        l[i]=min(l[i-1],a[i]);
    }
    
    for(int i=a.size()-2;i>=0;i--){
        r[i]=min(r[i+1],a[i]);
    }
    
    for(int i=1;i<a.size()-1;i++){
        if(a[i]<l[i-1] || a[i]<r[i+1]) answer++;   
    }
    
    if(a.size()>=2) answer+=2;
    
    return answer;
}