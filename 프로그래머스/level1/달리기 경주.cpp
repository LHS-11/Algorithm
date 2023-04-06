#include <string>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;
map<string,int> r; // 이름 -> 등수
map<int,string> n; // 등수 -> 이름
vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    for(int i=0;i<players.size();i++){
        r[players[i]]=i+1;
        n[i+1]=players[i];
    }
    
    for(auto c  : callings){
        int now=r[c];
        r[c]--;
        string front= n[now-1];
        r[front]++;
        
        n[now-1]=c;
        n[now]=front;
        
    }
    
    vector<pair<int,string>> v;
    for(auto it=r.begin();it!=r.end();it++){
        v.push_back({it->second,it->first});
    }
    
    sort(v.begin(),v.end());
    
    for(auto x : v){
        answer.push_back(x.second);
    }
    
    return answer;
}