#include<bits/stdc++.h>
using namespace std;
int cnt[1500];
priority_queue<int,vector<int>,greater<int>> pq;
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<pair<int,int>> time;
    
    for(auto v : book_time){
        string h="";
        h+=v[0][0];
        h+=v[0][1];
        string m="";
        m+=v[0][3];
        m+=v[0][4];
        int a=stoi(h)*60+stoi(m);
        h="";
        h+=v[1][0];
        h+=v[1][1];
        m="";
        m+=v[1][3];
        m+=v[1][4];
        int b=stoi(h)*60+stoi(m);
        time.push_back({a,b+10});        
    }
    
    sort(time.begin(),time.end());
    
    /*
    O(n) 풀이 -> 총 24시간으로 정해져 있으므로 객실이 필요한 시간대를 카운팅 한뒤 
    카운팅 한 값의 최대값을 구하면 필요한 최소 객실의 수가 된다.
    for(auto t : time){
        int st=t.first;
        int en=t.second;
        
        for(int i=st;i<en;i++){
            cnt[i]++;
            answer=max(cnt[i],answer);
        }
    }
    */
    
    // O(nlogn)
    for(int i=0;i<time.size();i++){
        int st=time[i].first;
        int en=time[i].second;
        
        while(pq.size() && st>=pq.top()){ // 가장 빨리 대실이 끝나는 시간과 다음 사람의 대실 시작 시간을 비교해서 겹치지 않는다면 한 객실에서 사용할 수 있으므로 pop 를 해줌
            pq.pop();
        }
        pq.push(en);
        answer=max(answer,(int)pq.size());
        
    }
        
    
    
    return answer;
}