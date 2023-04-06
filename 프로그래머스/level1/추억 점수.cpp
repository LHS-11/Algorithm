#include <string>
#include <vector>
#include<map>
using namespace std;
map<string,int> mp;
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for(int i=0;i<name.size();i++){
        mp[name[i]]=yearning[i];
    }
    
    for(auto ph : photo){
        int sum=0;
        for(auto p:ph) sum+=mp[p];
        answer.push_back(sum);
    }
    
    return answer;
}