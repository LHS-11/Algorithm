#include<bits/stdc++.h>
using namespace std;
struct compare{
    bool operator()(vector<int> a, vector<int> b){
        return a[1]>b[1]; // 소요시간 오름차순 (우선 순위 큐에서는 반대)
    }
};
priority_queue<vector<int>,vector<vector<int>>,compare> pq;
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(),jobs.end());
    
    int time=0,cnt=0;
    while(cnt<jobs.size() || pq.size()){

        if(cnt<jobs.size() && jobs[cnt][0]<=time){ // 시작 시간이 현재 진행 시간보다 적을 때
            pq.push(jobs[cnt++]); // pq에 넣는게 작업을 시작함
            continue;
        }   
        
        if(pq.size()){
            
            time+=pq.top()[1]; // 현재 진행 시간에 소요시간을 더하고
            answer+=time-pq.top()[0]; // 작업시간 = 현재 진행 시간 - 시작 시간
            pq.pop();
        }else{
            time=jobs[cnt][0]; // 현재 진행 시간을 해당 작업 시작 시간으로 변경
        }
    }
    
    answer/=jobs.size();
    
    
    return answer;
}