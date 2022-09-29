#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> ans(arr.size()); // copy 쓰기전에 벡터 크기 할당을 하고 사용해야함

    copy(arr.begin(), arr.end(), ans.begin());

    sort(ans.begin(), ans.end());

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == ans[0]) continue;
        answer.push_back(arr[i]);
    }
    if (!answer.size()) answer.push_back(-1);
    return answer;
}