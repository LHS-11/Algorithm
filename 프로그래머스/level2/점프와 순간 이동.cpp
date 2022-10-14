#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    // 이 문제는 수학 문제 => 최대로 순간 이동을 하는 순간의 건전지 수
    while (n) {
        if (n % 2 != 0) ans++;
        n /= 2;
    }

    return ans;
}