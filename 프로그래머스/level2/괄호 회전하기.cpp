#include<bits/stdc++.h>
using namespace std;
int solution(string s) {
	int answer = 0;

	int sz = s.size();

	for (int i = 0; i < sz; i++) {
		string s1 = s;
		rotate(s1.begin(), s1.begin() + i, s1.end());

		stack<char> stk;

		for (auto c : s1) {

			if (!stk.empty()) {
				if ((stk.top() == '(' && c == ')')
					|| (stk.top() == '{' && c == '}')
					|| (stk.top() == '[' && c == ']')) {
					stk.pop();
				}
				else stk.push(c);

			}
			else stk.push(c);

		}
		if (stk.empty()) answer++;
	}
	return answer;
}