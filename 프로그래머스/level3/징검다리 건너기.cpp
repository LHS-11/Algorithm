#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
int solution(vector<int> stones, int k) {
    int answer = INT_MAX;
    
    for(int i=0;i<k-1;i++){
        s.insert(stones[i]);
    }
    
    for(int i=k-1;i<stones.size();i++){
        s.insert(stones[i]);
        
        auto iter = --s.end();
        answer=min(answer,*iter);
        
        s.erase(s.find(stones[i-k+1]));
        
    }
    
    
    return answer;
}


/*
multimap 풀이
#include<bits/stdc++.h>
using namespace std;
multimap<int,int>mp;
int solution(vector<int> stones, int k) {
    int answer = 0;
    
    for(int i=0;i<k;i++){
        mp.insert({stones[i],i});
    }
    
    auto iter=mp.end();
    answer=(--iter)->first;
    
    for(int i=k;i<stones.size();i++){
        auto findIter= mp.find(stones[i-k]);
        mp.erase(findIter);
        
        mp.insert({stones[i],i});
        auto iter=mp.end();
        
        answer=min(answer,(--iter)->first);
    }
    
    
    return answer;
}
*/