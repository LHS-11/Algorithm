#include<bits/stdc++.h>
// DB 캐시를 적용할 때 캐시 크기에 따른 실행시간 측정 프로그램을 작성하시오.
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	deque<int> v;
	map<string, int> mp;

	for (auto& city : cities) {
		std::transform(city.begin(), city.end(), city.begin(), ::tolower);
	}

	// 재참조를 해줘야함 업데이트 
	for (int i = 0; i < cities.size(); i++) {

		if (v.size() == cacheSize) { // cache miss
			if (cacheSize == 0) {
				answer += 5;
			}
			else {
				if (!mp[cities[i]]) { // cache miss

					mp[cities[v.front()]]--;
					v.pop_front();

					mp[cities[i]]++;
					v.push_back(i);
					answer += 5;
				} // cache hit
				else {
					// 재정렬을 해야하는데
					// 1 2 3 4 2 3 5 
					// 1 2 3 4-> 1 3 4 2 -> 1 4 2 3 -> 4 2 3 5                    
					for (int j = 0; j < v.size(); j++) {
						if (cities[v[j]] == cities[i]) {
							v.erase(v.begin() + j);
							break;
						}
					}

					v.push_back(i);
					answer += 1;
				}
			}
		}
		else {
			if (mp[cities[i]]) { // cache heat
				for (int j = 0; j < v.size(); j++) {
					if (cities[v[j]] == cities[i]) {
						v.erase(v.begin() + j);
						break;
					}
				}

				v.push_back(i);
				answer += 1;
			}
			else { // cache miss
				v.push_back(i);
				mp[cities[i]]++;
				answer += 5;
			}
		}


	}

	return answer;
}