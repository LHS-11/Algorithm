#include<bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    // 문자열 정렬시 사전순으로 정렬 됨 -> 인접한 원소만 확인해주면 됨
    // 문자열은 크기에 상관없이 앞에서부터 비교
    // 접두어 맨 앞에 있어야함 

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].find(phone_book[i]) == 0) {
            answer = false;
            return answer;
        }
    }


    return answer;
}