#include <string>
#include <vector>
#include<stack>
#include<tuple>
#include<utility>
#include<algorithm>
#include<iostream>
using namespace std;
// struct S{
//     int stt;
//     int plt;
//     string d;
// };
vector<tuple<int,int,string>>v;
int toInt(string time){
    int h=stoi(time.substr(0,2));
    int m=stoi(time.substr(3,2));
    return h*60+m;
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    for(auto p : plans){
        v.push_back({toInt(p[1]),stoi(p[2]),p[0]});
    }
    
    sort(v.begin(),v.end());
    
    stack<pair<int,string>>stk; // 남아있는 시간, 과제 이름 
    
    int x,y;
    string z;
    tie(x,y,z)=v[0];
    for(int i=1;i<v.size();i++){
        int x1,y1;
        string z1;
        tie(x1,y1,z1)=v[i];
        
        if(x1<x+y){ // 현재 하던 것을 스택에 담음 
            stk.push({x+y-x1,z});
        }
        // else if(x1==(x+y)){ // 현재 하던 것을 끝내고 바로 새로운 과제를 선택 
        //     answer.push_back(z);
        // } 
        else{ // 현재 하던 것을 끝낼 수 있음 
            answer.push_back(z);
            x+=y;
            while(stk.size()){ // 남아 있는 과제를 스택에서 꺼내서 비교 
                int time=stk.top().first;
                string d=stk.top().second;
                
                if(x+time>x1) { // 새로운 과제를 할 시간이 돼서 스택에 다시 집어넣음
                    stk.pop();
                    stk.push({x+time-x1,d});
                    break;
                }
                x+=time; // 멈춰뒀던 과제 하나를 제거
                answer.push_back(d);
                stk.pop();
            }
        }
        x=x1; // 교체 
        y=y1;
        z=z1;
    }
    answer.push_back(z);
    
    while(stk.size()){
        answer.push_back(stk.top().second);
        stk.pop();
    }

    return answer;
}