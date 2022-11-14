#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int cnt[10];
int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end());
    reverse(score.begin(), score.end());

    int idx = 1;
    for (int i = 0; i < score.size(); i++) {
        if (m * idx - 1 == i) {
            answer += m * score[i];
            idx++;
        }
    }

    return answer;
}