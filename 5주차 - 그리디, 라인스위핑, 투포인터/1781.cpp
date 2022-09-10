#include<bits/stdc++.h>
using namespace std;
int n, t, ans;
vector<pair<int, int>> v;
priority_queue <int,vector<int>,greater<int>> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for(int i=0;i<n;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		auto cur = v[i];
		if (cur.first > t) {  // 현재 시간에 넣을 수 있는 최대 컵라면의 수 갱신
			t++;
			pq.push(cur.second);
		}
		else if (cur.first == t) {
			if (pq.top() < cur.second) {
				pq.pop();
				pq.push(cur.second);
			}
		}
	}
	while (pq.size()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
}