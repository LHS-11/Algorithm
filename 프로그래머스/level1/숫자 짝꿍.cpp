#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;
map<char, int> mpX, mpY;
string solution(string X, string Y) {
    string answer = "";

    for (auto c : X) mpX[c]++;
    for (auto c : Y) mpY[c]++;

    for (auto c : X) {
        if (mpX[c] && mpY[c]) {
            mpX[c]--;
            mpY[c]--;
            answer += c;
        }
    }

    sort(answer.begin(), answer.end());

    reverse(answer.begin(), answer.end());

    while (answer.size() > 1 && answer[0] == '0') {
        answer.pop_back();
    }

    if (answer.empty()) answer += "-1";

    return answer;
}