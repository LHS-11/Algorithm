#include<bits/stdc++.h>
using namespace std;
queue<int> q;
vector<vector<int>>v1{ // 키패드 좌표로 설정
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {-1,0,-1}
};
pair<int, int> v[12];
string solution(vector<int> numbers, string hand) {
    string answer = "";

    for (int i = 0; i < v1.size(); i++) { // 키패드 숫자마다 좌표 부여
        for (int j = 0; j < v1[i].size(); j++) {
            v[v1[i][j]] = { i,j };
        }
    }

    for (auto c : numbers) q.push(c);

    pair<int, int> l = { 3,0 };
    pair<int, int> r = { 3,2 };

    int disL = 0, disR = 0;

    while (q.size()) {
        int now = q.front();
        q.pop();

        disL = abs(v[now].first - l.first) + abs(v[now].second - l.second);
        disR = abs(v[now].first - r.first) + abs(v[now].second - r.second);

        if (now == 1 || now == 4 || now == 7) {
            answer += 'L';
            l = { v[now].first,v[now].second };
        }
        else if (now == 3 || now == 6 || now == 9) {
            answer += 'R';
            r = { v[now].first,v[now].second };
        }
        else {
            if (disL == disR) {
                if (hand == "right") {
                    answer += 'R';
                    r = { v[now].first,v[now].second };
                }
                else {
                    answer += 'L';
                    l = { v[now].first,v[now].second };
                }
            }
            else if (disL < disR) {
                answer += 'L';
                l = { v[now].first,v[now].second };
            }
            else {
                answer += 'R';
                r = { v[now].first,v[now].second };
            }
        }
    }


    return answer;
}