#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int idx = 0;
    for (int i = 0; i < number.size() - k; i++) { // number.size()-k 개 만큼 숫자를 선택해야함 

        int mx = 0;
        for (int j = idx; j <= i + k; j++) { // 인덱스를 k+1 개씩 쪼개면 그 안에서 하나는 무조건 선택이 돼야 한다!!
            if (mx < (number[j] - '0')) {
                mx = number[j] - '0';
                idx = j + 1;
            }
        }
        answer += to_string(mx);
    }


    return answer;
}