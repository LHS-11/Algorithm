#include <bits/stdc++.h>
using namespace std;
// 1. 9시부터 t분 간격으로 n번의 버스를 해싱 테이블로 만들기
// 2. 타임테이블에 맞춰서 1~n번째 버스까지 채울 수 있는 만큼 크루들 채우기
// 3. 1) n번째 버스가 m만큼 찼을 때, 마지막 승객 도착시간-1
//    2) n번째 버스가 다 차지 않았을 때, 버스 도착시간
multimap<int, int> bus;
int vis[2004], lastIdx = -1;
vector<int> ttb;
int change(string t)
{
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}
string solution(int n, int t, int m, vector<string> timetable)
{
    int answer;

    int cnt = n;
    int time = 540, i = 0;
    // 1. bus 타임테이블 만들기
    while (cnt--)
    {
        bus.insert({time + t * i, 0});
        i++;
    }

    // 타임테이블을 int로 변환
    for (auto t : timetable)
    {
        ttb.push_back(change(t));
    }

    sort(ttb.begin(), ttb.end());

    // 2. 가장 빠른 bus 부터 n번째 버스까지 인원을 다 채움
    for (auto it = bus.begin(); it != bus.end(); it++)
    {

        // if(it==--bus.end()) continue;
        for (int i = 0; i < ttb.size(); i++)
        {
            if (vis[i])
                continue;
            if (ttb[i] <= it->first && it->second < m)
            {
                (it->second)++;
                vis[i] = 1;
                lastIdx = i;
            }
        }
    }

    // 3. n번째 버스에 다 채운경우
    if ((--bus.end())->second == m)
    {
        answer = ttb[lastIdx] - 1;
        // 못채운 경우
    }
    else
    {
        answer = (--bus.end())->first;
    }

    string hour = (answer / 60) / 10 >= 1 ? to_string(answer / 60) : '0' + to_string(answer / 60);
    string mi = (answer % 60) / 10 >= 1 ? to_string(answer % 60) : '0' + to_string(answer % 60);
    string ans = hour + ":" + mi;

    return ans;
}