#include<bits/stdc++.h>
using namespace std;
/*
1. 인센티브를 받지 못하는  -> 이게 핵심.. 
2. 사원들의 순위 매기기 ( 동점일 경우 석차를 건너띔 )
v를 근무 태도 점수를 내림차순하고 동료 평가 점수를 오름차순 하는 이유 : 
v의 인덱스에서 i번째 인덱스보다 i+1번째 이상 인덱스는 근무 태도 점수가 무조건 같거나 낮기 때문에 
i+1~ 은 비교를 하지 않아도 되고, 1~i-1번째 인덱스까지만 비교를 하면 된다. 만약 동료 평가 점수까지 내림차순을 하게 되면 i-1번 인덱스가 근무 태도 점수가 같은데 동료 평가 점수가 더 높아서 인센티브를 받지 못하게 될 수 있다. 따라서 동료 평가 점수를 오름차순 함으로써 1~i-1번째만 확실하게 비교하기 쉽게 만들어 주기 위함
*/
int check[100004];
map<int,int> mp; 
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}
int solution(vector<vector<int>> scores) {
    int answer = 0;
    int sc1=scores[0][0],sc2=scores[0][1];
    
    vector<pair<int,int>> v;
    for(auto s : scores){
        v.push_back({s[0],s[1]});
    }
    sort(v.begin(),v.end(),cmp);
    
    vector<pair<int,int>> r;
    for(int i=0;i<v.size();i++){
        int flag=0;
        
        for(int j=0;j<i;j++){
            if(v[j].second>v[i].second) {
                flag=1;
                break;
            }
        }
        
        if(flag){
            if(v[i].first==sc1 && v[i].second==sc2) return -1;
            check[i]=1;
        }else{
            r.push_back({v[i].first+v[i].second,i});
        }
    }
    
    sort(r.begin(),r.end());
    
    int rank=1;
    for(int i=r.size()-1;i>=0;i--){
        if(check[r[i].second]) continue;
        if(!mp[r[i].first]) mp[r[i].first]=rank;
        if(v[r[i].second].first==sc1 && v[r[i].second].second==sc2) 
            return mp[r[i].first];
        rank++;
    }
    
    
    return answer;
}