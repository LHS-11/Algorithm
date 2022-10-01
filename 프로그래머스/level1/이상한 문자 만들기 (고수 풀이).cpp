#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            idx = 0;
        }
        else {
            idx & 1 ? answer += tolower(s[i]) : answer += toupper(s[i]);
            idx++;
        }
    }

    return answer;
}