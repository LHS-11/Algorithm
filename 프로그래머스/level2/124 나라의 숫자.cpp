#include<bits/stdc++.h>
using namespace std;
string s = "";
string go(int k) {

    if (k == 0) return "";

    string s = "";
    if (k % 3 == 0) {
        return s += go(k / 3 - 1) + "4";
    }
    else if (k % 3 == 1) {
        return s += go(k / 3) + "1"; // 4 
    }
    else if (k % 3 == 2) {
        return s += go(k / 3) + "2";
    }
    // go(4) -> s=go(1)+"1" -> s=go(0)+"1" -> 0

}
string solution(int n) {
    string answer = "";
    answer = go(n);

    return answer;
}