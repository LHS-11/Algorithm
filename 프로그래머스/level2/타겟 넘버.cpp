#include<bits/stdc++.h>
using namespace std;
int cnt;
vector<int> v;
void go(int idx, int a, int k, int sz) {

    if (idx == sz) {
        if (a == k) cnt++;
        return;
    }

    go(idx + 1, a + v[idx], k, sz);
    go(idx + 1, a - v[idx], k, sz);

}
int solution(vector<int> numbers, int target) {
    int answer = 0;

    v.resize(numbers.size());

    copy(numbers.begin(), numbers.end(), v.begin());


    go(0, 0, target, numbers.size());

    answer = cnt;


    return answer;
}