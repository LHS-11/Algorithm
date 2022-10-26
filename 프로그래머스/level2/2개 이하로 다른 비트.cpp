#include <string>
#include <vector>
typedef long long ll;
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (auto n : numbers) {
        ll bit = 1;
        while ((n & bit) != 0) bit <<= 1;
        answer.push_back(n + bit - (bit >> 1));
    }


    return answer;
}