#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    double x, y; // 가로, 세로

    double bro = brown, yel = yellow;

    for (int i = 3; i <= 5000; i++) { // 가로 
        if ((bro + 4) / 2 - i == (yel / (i - 2) + 2)) {
            y = (bro + 4) / 2 - i;
            x = i;
            break;
        }
    }
    answer.push_back(max(x, y));
    answer.push_back(min(x, y));




    return answer;
}