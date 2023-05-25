#include<bits/stdc++.h>
using namespace std;
unordered_map<long long , long long> parent;
/*
map 은 트리구조, unordered_map은 해쉬테이블 구조 
*/
long long find(long long k){
    if(!parent[k]) return k;
    return parent[k]=find(parent[k]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(auto room : room_number){
        
        if(!parent[room]){
            parent[room]=room+1;
            answer.push_back(room);
        }else{
            long long nxt=find(room);
            parent[nxt]=nxt+1;
            answer.push_back(nxt);
        }
        
    }
    
    return answer;
}
/*
#include<bits/stdc++.h>
using namespace std;
unordered_map<long long, int> mp;
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(auto room : room_number){
        long long l=1,r=k;
        long long ans;
        
        while(l<=r){
            long long m=(l+r)/2;
            
            if(m>=room && !mp[m]){
                r=m-1;
                ans=m;
            }else l=m+1;
        }
        
        mp[ans]=1;
        answer.push_back(ans);
    }
    
    
    return answer;
}

*/