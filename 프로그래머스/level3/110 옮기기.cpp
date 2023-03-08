#include<bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    
    for(auto ss : s){

        stack<char>stk; // 1이 나오면 담고 0이 나왔을때 stack의 사이즈가 2이상이면 pop 하기 
        vector<string> v;
        
        string str="";
        for(int i=0 ;i<ss.size();i++){
            str+=ss[i];
            if(ss[i]=='1') stk.push(ss[i]);
            else{
                if(stk.size()>=2){
                    stk.pop();
                    stk.pop();
                    v.push_back("110");
                    str.erase(str.size()-3,3);
                }else if(stk.size()) stk.pop();
            }
        }
        int flag=1;
        for(int i=str.size()-1;i>=0;i--){
                                    
            if(str[i]=='0'){
                for(int j=0;j<v.size();j++){
                    str.insert(i+1,"110");
                }
                answer.push_back(str);
                flag=0;
                break;
            }else{
                flag=1;
            }
        }
        
        if(flag){
            for(int i=0;i<v.size();i++){
                str.insert(0,"110");
            }
            answer.push_back(str);
        }
        
    }
    
    return answer;
}