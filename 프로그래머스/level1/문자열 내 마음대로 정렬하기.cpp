#include<bits/stdc++.h>
using namespace std;
int x;
bool cmp(string a, string b) {
    // if(a[x]==b[x]) return a<b;
    // return a[x]<b[x];

    return  a[x] == b[x] ? a < b : a[x] < b[x];
}
vector<string> solution(vector<string> strings, int n) {
    x = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}