#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    // 아스키코드 값을 조작할 때, char 형에 연산을 하지말고 
    // int 형에다가 계산을 하고 string 에 더할 때 (char) 로 형변환 해서 진행
    int x;
    for (auto c : s) {
        if (c >= 'A' && c <= 'Z') {
            x = c + n;
            if (x > 'Z') x = x - 'Z' - 1 + 'A';
            answer += char(x);

        }
        else if (c >= 'a' && c <= 'z') {
            x = c + n;
            if (x > 'z') x = x - 'z' - 1 + 'a';
            answer += char(x);

        }
        else answer += c;

        if (c >= 'A' && c <= 'z') {
            
        }
    }

    return answer;
}