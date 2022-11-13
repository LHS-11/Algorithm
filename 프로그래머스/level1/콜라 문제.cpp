#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n > a - 1) {
        int tmp = n / a * b;
        answer += tmp;
        tmp += (n % a);
        n = tmp;
    }
    return answer;
}