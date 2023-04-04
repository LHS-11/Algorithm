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
    
    stack<pair<int,string>>stk; // �����ִ� �ð�, ���� �̸� 
    
    int x,y;
    string z;
    tie(x,y,z)=v[0];
    for(int i=1;i<v.size();i++){
        int x1,y1;
        string z1;
        tie(x1,y1,z1)=v[i];
        
        if(x1<x+y){ // ���� �ϴ� ���� ���ÿ� ���� 
            stk.push({x+y-x1,z});
        }
        // else if(x1==(x+y)){ // ���� �ϴ� ���� ������ �ٷ� ���ο� ������ ���� 
        //     answer.push_back(z);
        // } 
        else{ // ���� �ϴ� ���� ���� �� ���� 
            answer.push_back(z);
            x+=y;
            while(stk.size()){ // ���� �ִ� ������ ���ÿ��� ������ �� 
                int time=stk.top().first;
                string d=stk.top().second;
                
                if(x+time>x1) { // ���ο� ������ �� �ð��� �ż� ���ÿ� �ٽ� �������
                    stk.pop();
                    stk.push({x+time-x1,d});
                    break;
                }
                x+=time; // ����״� ���� �ϳ��� ����
                answer.push_back(d);
                stk.pop();
            }
        }
        x=x1; // ��ü 
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