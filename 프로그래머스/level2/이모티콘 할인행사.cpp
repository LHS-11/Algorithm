#include <bits/stdc++.h>
using namespace std;
// n명의 카카오톡 사용자들에게 이모티콘 m개를 할인하여 판매합니다.
// 이모티콘마다 할인율은 다를 수 있으며, 할인율은 10%, 20%, 30%, 40% 중 하나로 설정됩니다.
// 이때, 행사 목적을 최대한으로 달성했을 때의 이모티콘 플러스 서비스 가입 수와 이모티콘 매출액을 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해주세요.
int discount[4] = {10, 20, 30, 40};
vector<int> v;
vector<pair<int, int>> ans;
vector<vector<int>> u;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}
void go(int idx, vector<int> emoticons)
{

    if (idx == emoticons.size())
    {

        int cnt = 0;
        int sum = 0; // 이모티콘 구매 비용
        for (auto c : u)
        { // 최대 100

            int limit = c[0];
            int m = c[1];

            int sum1 = 0;
            for (int i = 0; i < v.size(); i++)
            { // 이모티콘의 길이 최대 7
                if (limit <= discount[v[i]])
                { // 이모티콘 구매 제한
                    sum1 += ((100 - discount[v[i]]) * emoticons[i] * 0.01);
                }
            }

            if (sum1 >= m)
            {
                cnt++;
            }
            else
                sum += sum1;
        }

        ans.push_back({cnt, sum});

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        v.push_back(i);
        go(idx + 1, emoticons);
        v.pop_back();
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{

    // 1. 이모티콘 플러스 서비스 가입자를 최대화해서 만들어보기

    // 4^7 => 2^14 완탐으로 돌려서 구하고 모든 답을 vector<pair<int,int>>v 에다가 넣은뒤 정렬후 답 도출
    u = users;
    go(0, emoticons);
    sort(ans.begin(), ans.end(), cmp);

    // 2. 최대화하면서 이모티콘 매출액도 최대화하기
    return {ans[0].first, ans[0].second};
}