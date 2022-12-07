#include<bits/stdc++.h>
using namespace std;
vector<int> go(int k) {
    vector<int> v;

    for (int i = 2; i <= k; i++) {
        if (k % i == 0) {
            v.push_back(i);
        }
    }
    return v;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    vector<int> A, B;
    A = arrayA;
    B = arrayB;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // 1번 상황
    int x = A[0];
    vector<int> v = go(x);

    for (auto c : v) {
        int flag = 0;

        for (int i = 1; i < A.size(); i++) {
            if (A[i] % c != 0) {
                flag = 1;
            }
        }
        if (!flag) {
            int flag = 0;
            for (auto b : B) {
                if (b % c == 0) {
                    flag = 1;
                }
            }
            if (!flag) answer = max(answer, c);
        }
    }


    // 2번 상황
    x = B[0];
    v = go(x);
    for (auto c : v) {
        int flag = 0;
        for (int i = 1; i < B.size(); i++) {
            if (B[i] % c != 0) {
                flag = 1;
            }
        }

        if (!flag) {
            int flag = 0;
            for (auto a : A) {
                if (a % c == 0) {
                    flag = 1;
                }
            }
            if (!flag) answer = max(answer, c);
        }
    }


    return answer;
}