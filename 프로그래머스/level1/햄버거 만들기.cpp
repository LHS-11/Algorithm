#include<bits/stdc++.h>
using namespace std;
// 1 2 3 1 
int solution(vector<int> ingredient) {
    int answer = 0;

    string s = "";
    for (auto i : ingredient) s += to_string(i);

    string h = "1231";
    int idx = 0;
    while (1) {
        auto iter = s.find(h, idx);
        if (iter != string::npos) {
            s.erase(iter, 4);
            idx = iter - 3;
            if (idx < 0) idx = 0;
            answer++;
        }
        else break;
    }

    return answer;
}