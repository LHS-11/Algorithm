#include <bits/stdc++.h>
using namespace std;
/*
11011 과 00000 만 나오는 구조로 나열하다 보면 특징이 나오는데,
1번째 유사 칸토어 비트열은 11011 => 5
2번째 유사 칸토어 비트열은 11011 11011 00000 11011 11011 => 5/5/5/5/5
3번째 유사 칸토어 비트열은
11011 11011 00000 11011 11011 / 11011 11011 00000 11011 11011 / 00000 00000 00000 00000 00000 / 11011 11011 00000 11011 11011 / 11011 11011 00000 11011 11011 => 25/25/25/25/25
구간 5개로 나눠서 생각하면 되는데,
예를들어 n=3 에서 52는 52/5=10 + 1 = 11 번째 묶음이다. (5개를 하나로 보면) 이 묶음은 n=3인 칸토어 비트열 일때의 묶음이고 이때 또 5로 나누면 11/2=5+1 =6 번째 묶음 2번째 칸토어 비트열의 6번째 묶음에 해당한다 따라서 00000 중 하나에 속하기 때문에 52는 0을 가지게 된다.

이로 봤을 때 n 을 5로 계속 나누면서 나머지가 3인지를 확인하다가 n이 5이하가 됐을 때 +1을 해주면 된다.

*/
int solution(int n, long long l, long long r)
{
    int answer = 0;

    for (long long i = l; i <= r; i++)
    {
        long long tmp = i;
        if (tmp % 5 == 3)
            continue; // 11011 을 기본으로 생각하고 index 가 3일때는 0이기 때문에 제외해준다

        while (tmp > 0)
        {

            if (tmp % 5 == 0)
                tmp /= 5;
            else
                tmp = tmp / 5 + 1;

            if (tmp % 5 == 3)
                break;
            else if (tmp <= 5)
            {
                answer++;
                break;
            }
        }
    }

    return answer;
}