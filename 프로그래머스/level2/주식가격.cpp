#include<bits/stdc++.h>
using namespace std;
int times[100004];
stack<int> s;
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    // 이중포문 풀이
    int sz = prices.size();

    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (prices[i] > prices[j]) {
                times[i] = j - i;
                break;
            }

            if (j == sz - 1) times[i] = sz - 1 - i;
        }
    }

    for (int i = 0; i < prices.size(); i++) answer.push_back(times[i]);

    //  스택 풀이
    //     for(int i=0;i<prices.size();i++){
    //         while(s.size() && prices[s.top()]>prices[i]){
    //             times[s.top()]=i-s.top();
    //             s.pop();
    //         }
    //         s.push(i);
    //     }

    //     while(s.size()){
    //         times[s.top()]=prices.size()-1-s.top();
    //         s.pop();
    //     }

    //     for(int i=0;i<prices.size();i++) answer.push_back(times[i]);


    return answer;
}