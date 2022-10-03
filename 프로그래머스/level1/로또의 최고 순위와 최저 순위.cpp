#include <string>
#include <vector>

using namespace std;
int ranking[] = { 6,6,5,4,3,2,1 };
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same = 0;
    int cnt = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (!lottos[i]) cnt++;
        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j]) same++;
        }
    }

    answer.push_back(ranking[same + cnt]);
    answer.push_back(ranking[same]);

    return answer;
}