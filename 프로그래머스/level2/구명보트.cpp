#include<bits/stdc++.h>
using namespace std;
int vis[50004];
int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int en = people.size() - 1;


    for (int st = 0; st < people.size(); st++) {

        if (st > en) {
            for (int i = 0; i <= en; i++) if (!vis[i]) answer++;
            break;
        }

        while (st<en && people[st] + people[en]>limit) {
            vis[en]++;
            answer++;
            en--;
        }
        if (people[st] + people[en] <= limit) {
            vis[st]++;
            vis[en]++;
            en--;
            answer++;
        }
    }
    // sort(people.begin(), people.end());
    // reverse(people.begin(), people.end());
    // int N = (int)people.size();
    // int res = 0;
    // for (int i = 0, j = N - 1; i <= j; i++) {
    //     if (people[i] + people[j] <= limit) {
    //         j--;
    //     }
    //     res++;
    // }
    // return res;
    return answer;
}