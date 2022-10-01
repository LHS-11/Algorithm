#include<bits/stdc++.h>
using namespace std;
stack<int> stk;
vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(auto c : arr){
        if(stk.empty()){
            stk.push(c);
        }else{
            if(stk.top()==c) continue;
            stk.push(c);
        }
    }
    while(stk.size()){
        answer.push_back(stk.top());
        stk.pop();
    }
    reverse(answer.begin(),answer.end());
    return answer;
}