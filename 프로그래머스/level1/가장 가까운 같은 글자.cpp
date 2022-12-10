#include<bits/stdc++.h>
using namespace std;
// 위치표시 
int vis[10004];
vector<int> solution(string s) {
    vector<int> answer;

    fill(vis, vis + 10004, -1);

    for (int i = 0; i < s.size(); i++) {
        if (vis[s[i] - 'a'] == -1) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(i - vis[s[i] - 'a']);
        }
        vis[s[i] - 'a'] = i;
    }


    return answer;
}