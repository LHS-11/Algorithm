#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }

    sort(answer.begin(), answer.end());

    // 중복제거 unique => 중복이 된 원소들 뒤로 다 보내고 보낸 원소들 중에 첫번째 인덱스가 나옴
    answer.erase(unique(answer.begin(), answer.end()), answer.end());


    return answer;
}