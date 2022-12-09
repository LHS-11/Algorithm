#include<bits/stdc++.h>
using namespace std;
// 무적권을 최대한 많은 적수가 나왔을 때 써야 최적화이지 않을까?
// 무적권을 쓸지 안쓸지를 선택해야함 -> 어떻게 해야할까?
// 만약 현재 가지고 있는 병사보다 적의 수가 크다면 무적권을 무조건 사용해야함
// 
int solution(int n, int k, vector<int> enemy) {
    int answer = enemy.size();

    priority_queue<int> pq;

    for (int i = 0; i < enemy.size(); i++) {
        pq.push(enemy[i]);
        n -= enemy[i];
        if (n < 0) {
            if (k > 0 && pq.size()) {
                k--;
                n += pq.top();
                pq.pop();
            }
            else {
                answer = i;
                break;
            }
        }
    }


    return answer;
}