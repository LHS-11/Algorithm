#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> nums)
{
    //     int answer = 0;
    //     int sz=nums.size()/2;

    //     sort(nums.begin(),nums.end());
    //     nums.erase(unique(nums.begin(),nums.end()),nums.end());

    //     nums.size()>sz ? answer=sz : answer=nums.size();
        // return answer;

    set<int> s;

    for (auto c : nums) s.insert(c);

    return min(s.size(), nums.size() / 2);


}