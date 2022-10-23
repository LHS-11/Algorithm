#include<bits/stdc++.h>
using namespace std;
int sumfix[3004];
int vis[1000004];
int solution(vector<int> elements) {
    int answer = 0;

    int sz = elements.size();

    for (int i = 0; i < sz - 1; i++) elements.push_back(elements[i]);


    for (int i = 0; i < elements.size(); i++) {
        sumfix[i + 1] = sumfix[i] + elements[i];
    }

    for (int i = 1; i <= sz; i++) {
        for (int j = 0; j < sz; j++) {
            int sum = sumfix[i + j] - sumfix[j];
            if (!vis[sum] && sum > 0) {
                answer++;
                vis[sum] = 1;
            }
        }
    }



    return answer;
}