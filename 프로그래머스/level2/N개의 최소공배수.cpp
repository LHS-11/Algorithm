#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int solution(vector<int> arr) {
    int answer = 0;

    answer = arr[0];


    for (int i = 1; i < arr.size(); i++) {
        answer = lcm(arr[i], answer);
    }


    return answer;
}
