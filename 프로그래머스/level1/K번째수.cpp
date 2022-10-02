#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        auto cur = commands[i];
        vector<int> arr(cur[1] - cur[0] + 1);

        copy(array.begin() + cur[0] - 1, array.begin() + cur[1], arr.begin()); 
        // copy 함수 쓰기 전에 크기가 지정 되어 있어야 함
        // copy ( 복사하려는 벡터의 iterator (첫번째 범위), 복사하려는 벡터의 iterator (두번째 범위+1), 복사해서 넣을 벡터 iter)

        sort(arr.begin(), arr.end());
        answer.push_back(arr[cur[2] - 1]);

    }

    return answer;
}