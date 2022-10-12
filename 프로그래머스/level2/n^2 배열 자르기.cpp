#include <string>
#include <vector>
typedef long long ll;
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (ll i = left; i <= right; i++) {
        answer.push_back(max(i / n, i % n) + 1);
    }


    return answer;
}
