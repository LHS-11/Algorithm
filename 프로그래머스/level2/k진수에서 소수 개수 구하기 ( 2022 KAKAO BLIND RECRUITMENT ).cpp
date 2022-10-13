#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool chk(ll k) { // 소수 판별
    if (k <= 1) return false;
    else if (k == 2) return true;

    for (ll i = 2; i * i <= k; i++) {
        if (k % i == 0) return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;

    // 10진법 -> 3진법 
    string s = "";
    while (n) {
        s = to_string(n % k) + s;
        n /= k;
    }

    string s1 = "";
    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '0') {
            if (s[i - 1] == '0') continue;
            cout << s1 << endl;
            if (chk(stol(s1))) answer++;
            s1 = "";

        }
        else s1 += s[i];

    }

    if (s1.size() && chk(stol(s1))) answer++;

    return answer;
}