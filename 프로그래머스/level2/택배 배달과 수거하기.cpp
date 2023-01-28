#include <bits/stdc++.h>
using namespace std;
// vector<pair<int,int>> d;
// vector<pair<int,int>> p;
// 수거해야할 택배 -> 상관없이 cap 여유가 있으면 그냥 가져가면 됨
// 배달해야할 택배 -> 창고에서 가져가야 함
// 무조건 배달한 곳이 있는 집은 가야되니깐 (그 집의 왕복 거리를 계산해야하는데 )
// 되도록 적은 거리의 집을 최소한으로 가기 위함
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    vector<int> d = deliveries;
    vector<int> p = pickups;

    int d_cnt = 0; // 배달할 수 있는 양
    int p_cnt = 0; // 수거할 수 있는 양
    for (int i = n - 1; i >= 0; i--)
    { // 집을 모두 하나씩 돌면서 얼마나 왕복해야 하는지를 계산

        if (d[i] || p[i])
        { // 배달하거나 수거가 있는 집인지 확인

            int cnt = 0;
            while (d_cnt < d[i] || p_cnt < p[i])
            {
                d_cnt += cap;
                p_cnt += cap;
                cnt++;
            }
            answer += (i + 1) * 2 * cnt;
            d_cnt -= d[i];
            p_cnt -= p[i];
        }
    }
    return answer;
}