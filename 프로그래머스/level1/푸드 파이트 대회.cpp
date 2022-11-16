#include<bits/stdc++.h>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    answer += '0';

    for (int i = food.size() - 1; i > 0; i--) {
        int n = food[i] / 2;

        while (n) {
            answer = to_string(i) + answer;
            answer = answer + to_string(i);
            n--;
        }
    }

    return answer;
}