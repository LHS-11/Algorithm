#include <string>
#include <vector>
using namespace std;
#define mod 1000000007
long long dp[5004];
int solution(int n) {

    dp[0] = 1;
    dp[1] = 0, dp[3] = 0, dp[5] = 0;
    dp[2] = 3;
    dp[4] = 11;
    for (int i = 6; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] += (dp[i - 2] * 3) % mod; // dp[4]=dp[2]*3
            for (int j = 2; j <= i - 4; j += 2) {
                dp[i] += (2 * dp[j]) % mod;
            }
            dp[i] += 2;
        }
        else dp[i] = 0;
        dp[i] %= mod;
    }

    return dp[n];
}