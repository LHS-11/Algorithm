#include<bits/stdc++.h>
using namespace std;
int vis[101];
vector<int> v;
int solution(vector<int> cards) {
    int answer = 1;

    int st = 1;
    while (1) {
        int cnt = 0;
        while (!vis[cards[st - 1]]) {
            vis[cards[st - 1]] = 1; // vis[8]= 1, vis[4]= 1, vis[7]=1 , vis[8]
            st = cards[st - 1]; // st=8 , st=7, st = 1
            cnt++;
        }
        cout << endl;
        v.push_back(cnt);

        int flag = 0;
        for (auto c : cards) {
            if (!vis[c]) {
                flag = 1;
                break;
            }
        }
        if (!flag) break;

        while (vis[cards[st - 1]]) {
            st++;
        }
    }
    sort(v.begin(), v.end());

    answer = v[v.size() - 1] * v[v.size() - 2];


    return answer;
}

