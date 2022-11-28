#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& ans, int bit) {
    for (int i = 0; i < ans.size(); i++) {
        if ((bit & ans[i]) == ans[i]) return false;
    }
    return true;
}
int solution(vector<vector<string>> relation) {

    vector<int> ans;

    int n = relation.size();
    int m = relation[0].size();

    for (int i = 1; i < (1 << m); i++) {
        set<string> s;

        for (int j = 0; j < n; j++) {
            string str = "";
            for (int k = 0; k < m; k++) {
                if (i & (1 << k)) str += relation[j][k];
            }
            s.insert(str);

            if (s.size() == n && check(ans, i)) {
                ans.push_back(i);
            }
        }
    }

    return ans.size();
}