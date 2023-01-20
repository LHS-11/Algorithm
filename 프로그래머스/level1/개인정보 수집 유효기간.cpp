#include <bits/stdc++.h>
using namespace std;
// 파기해야 할 개인정보의 번호를 오름차순으로 정렬해서 답을 도출
map<char, int> term;
vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;

    for (int i = 0; i < terms.size(); i++)
    {
        term[terms[i][0]] = stoi(terms[i].substr(2));
    }

    int now = stoi(today.substr(0, 4)) * 12 * 28 + stoi(today.substr(5, 2)) * 28 + stoi(today.substr(8, 2));

    for (int i = 0; i < privacies.size(); i++)
    {

        char a; // 원소
        int y;  // 수집일자
        a = privacies[i][privacies[i].size() - 1];
        y = stoi(privacies[i].substr(0, 4)) * 12 * 28 + stoi(privacies[i].substr(5, 2)) * 28 + stoi(privacies[i].substr(8, 2));

        if (y + term[a] * 28 <= now)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}