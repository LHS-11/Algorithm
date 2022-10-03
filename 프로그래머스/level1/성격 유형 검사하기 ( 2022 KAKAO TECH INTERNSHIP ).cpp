#include<bits/stdc++.h>
using namespace std;
int score[] = { 3,2,1,0,1,2,3 };
map<char, int> mp;
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    for (int i = 0; i < survey.size(); i++) {

        choices[i] >= 4 ? mp[survey[i][1]] += score[choices[i] - 1] : mp[survey[i][0]] += score[choices[i] - 1];

    }
    mp['R'] >= mp['T'] ? answer += 'R' : answer += 'T';
    mp['C'] >= mp['F'] ? answer += 'C' : answer += 'F';
    mp['J'] >= mp['M'] ? answer += 'J' : answer += 'M';
    mp['A'] >= mp['N'] ? answer += 'A' : answer += 'N';

    return answer;
}