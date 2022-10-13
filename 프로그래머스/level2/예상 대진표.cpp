#include <iostream>

using namespace std;
bool chk(int a, int b) {
    if ((a % 2 == 0 && a == b + 1) || (a % 2 != 0 && a + 1 == b)) {
        return true;
    }
    return false;
}
int solution(int n, int a, int b)
{
    int answer = 0;

    while (!chk(a, b)) {
        if (a % 2 == 0) a /= 2; 
        else a = a / 2 + 1;
        
        if (b % 2 == 0) b /= 2;
        else b = b / 2 + 1; // 4 -> 2 

        answer++;
    }

    return answer + 1;
}