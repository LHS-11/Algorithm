#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}
long long solution(int w, int h) {
    return ((long long)w * h) - (w + h) + gcd(w, h);
}