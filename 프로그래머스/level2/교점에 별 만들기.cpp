#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;
typedef long long ll;
set<pair<ll, ll>> get(vector<tuple<int,int,int>> v){
    
    set<pair<ll,ll>> s;
    
    for(int i=0;i<v.size();i++){
        ll a,b,e;
        tie(a,b,e)=v[i];
        for(int j=i+1;j<v.size();j++){
            ll c,d,f;
            tie(c,d,f)=v[j];
            
            if(a*d-b*c==0) continue; 
            
            double x=(double)(b*f-e*d)/(double)(a*d-b*c);
            double y=(double)(e*c-a*f)/(double)(a*d-b*c);
            
            if(x-(ll)x==0 && y-(ll)y==0){
                s.insert({x,y});
            }
        }
    }
    
    return s;
}
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<tuple<int,int,int>> v;
    for(auto l : line){
        v.push_back({l[0],l[1],l[2]});
    }
    
    //1. 교점 구하기
    set<pair<ll,ll>> s=get(v);

    //2. 크기 구하기
    ll minX=LLONG_MAX;
    ll maxX=LLONG_MIN;
    ll minY=LLONG_MAX;
    ll maxY=LLONG_MIN;
    
    for(auto c : s){
        minX=min(minX,c.first);
        maxX=max(maxX,c.first);
        minY=min(minY,c.second);
        maxY=max(maxY,c.second);
    }
    
    for(ll i=minY;i<=maxY;i++){
        string str="";
        for(ll j=minX;j<=maxX;j++){
            str+=".";
        }
        answer.push_back(str);
    }
    
    // 3. 그래프에 별 넣기
    for(auto c : s){
        // answer[maxY-c.second][c.first-minX]='*';
        answer[c.second-minY][c.first-minX]='*';
        
    }
    reverse(answer.begin(),answer.end());
    
    return answer;
}