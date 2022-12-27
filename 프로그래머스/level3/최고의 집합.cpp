#include<bits/stdc++.h>
using namespace std;
vector<int> solution(int n, int s) {
    vector<int> answer;
    // n개의 자연수를 모아서 합이 s가 되면서 그 집합의 곱이 최대인 집합을 구하는 문제
    // 1. 합이 s 가 되면서 n개인 집합을 어떻게 구할 것인가?

    int k = s / n;
    int mod = s % n;

    if (s < n) {
        return { -1 };
    }
    else {
        if (mod) {
            n -= mod;
            while (mod--) {
                answer.push_back(k + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            answer.push_back(k);
        }
    }


    sort(answer.begin(), answer.end());

    return answer;
}