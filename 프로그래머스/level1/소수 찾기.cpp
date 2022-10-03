#include <string>
#include <vector>

using namespace std;
int go(int n) {
    int cnt = 0;
    for (int i = 2; i <= n; i++) { // 2~n번까지 확인
        int flag = 0;
        for (int j = 2; j * j <= i; j++) { // 약수인지 확인
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) cnt++;
    }

    return cnt;
}

int solution(int n) {
    return go(n);
}