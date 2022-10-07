#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    // for(int i=1;i<=n;i++){
    //     int sum=0;
    //     for(int j=i;j<=n;j++){
    //         sum+=j;
    //         if(sum==n) answer++;
    //         else if(sum>n) break;
    //     }
    // }

    int sum1 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += i;
        int k = n - sum1;
        int div = i + 1;

        if (k >= div && k % div == 0) answer++;

    }

    return answer;
}