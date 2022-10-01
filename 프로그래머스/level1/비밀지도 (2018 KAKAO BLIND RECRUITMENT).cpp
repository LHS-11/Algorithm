#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> change(vector<int> arr1, int n) {
    vector<vector<int>> v;

    for (int i = 0; i < n; i++) {

        // 십진수 -> 이진수로 치환 
        vector<int> v1;
        while (arr1[i]) {
            v1.push_back(arr1[i] % 2);
            arr1[i] /= 2;
        }
        while (v1.size() != n) {
            v1.push_back(0);
        }
        reverse(v1.begin(), v1.end());

        v.push_back(v1);
    }

    return v;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    vector<vector<int>> v1 = change(arr1, n);
    vector<vector<int>> v2 = change(arr2, n);

    for (int i = 0; i < v1.size(); i++) {
        string s = "";

        for (int j = 0; j < v1[i].size(); j++) {
            int x = v1[i][j] | v2[i][j];

            if (x == 1) s += '#';
            else s += ' ';

        }

        answer.push_back(s);
    }

    return answer;
}