#include<bits/stdc++.h>
// 그리디 문제 
using namespace std;
bool cmp (vector<int> a,vector<int> b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(),targets.end(),cmp);
    
    for(int i=0,en=0;i<targets.size();i++){
        if(en<=targets[i][0]){
            en=targets[i][1];
            answer++;
        }
    }
    return answer;
}
/*#include<bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(),targets.end());
    
    priority_queue<int,vector<int>,greater<int>>pq;
    
    for(auto t : targets){
        int st=t[0];
        int en=t[1];
        
        int flag=0;
        while(pq.size() && pq.top()<=st){
            pq.pop();
            flag=1;
        }
        if(flag) {
            answer++;
            while(pq.size()) pq.pop();
        }
        pq.push(en);
        
    }
    if(pq.size()) answer++;
    return answer;
}*/