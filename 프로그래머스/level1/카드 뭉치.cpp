#include<bits/stdc++.h>
using namespace std;
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    /*
    cards1,cards2 에 인덱스 번호를 각각 시작해서 
    goal 을 돌면서 사용가능한지 확인 
    */
    int idx1=0,idx2=0;
    int flag=0;
    for(int i=0;i<goal.size();i++){
        if(cards1[idx1]==goal[i]){
            idx1++;
        }
        else if(cards2[idx2]==goal[i]){
            idx2++;
        }
        else {
            flag=1;
            break;
        }
    }
    if(!flag) answer="Yes";
    else answer="No";
    return answer;
}