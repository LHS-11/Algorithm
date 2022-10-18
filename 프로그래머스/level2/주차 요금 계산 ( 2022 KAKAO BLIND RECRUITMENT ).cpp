#include<bits/stdc++.h>
using namespace std;
double in_time[10004]; // 입차 시간
double times[10004]; // 누적 시간
vector<int> v; // 차량 번호
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    for (auto s : records) {
        double time = stoi(s.substr(0, 2)) * 60;
        double seconds = stoi(s.substr(3, 2));
        int num = stoi(s.substr(6, 4));
        v.push_back(num);

        if (s.substr(10).size() == 3) { // in
            in_time[num] = time + seconds;
        }
        else { // out
            times[num] += time + seconds - in_time[num];
            in_time[num] = -1;
        }

    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto c : v) {
        if (in_time[c] >= 0) {
            times[c] += 23 * 60 + 59 - in_time[c];
        }
    }

    for (auto c : v) {
        if (times[c] - fees[0] > 0) {
            answer.push_back(fees[1] + (ceil((times[c] - fees[0]) / fees[2]) * fees[3]));
        }
        else
            answer.push_back(fees[1]);

    }

    return answer;
}