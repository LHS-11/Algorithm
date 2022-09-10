#include<bits/stdc++.h>
using namespace std;
int n, d[10001], ans;
priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
int main() {
	ios::sync_with_stdio(0);

	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}
	while (pq.size()) { // 가장 큰 금액을 받는 강연을 우선으로 해서 d 배열에 날짜와 금액을 채워 넣는 알고리즘, 
						//만약 날짜에 이미 강연이 잡혀있다면 날짜-1을 반복해서 가능한 날짜에 강연을 잡는다
		auto cur = pq.top();
		pq.pop();
		while (cur.second!=0) {
			if (!d[cur.second]) {
				d[cur.second] = cur.first;
				break;
			}
			cur.second--;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (d[i]) ans += d[i];
	}
	cout << ans;
}