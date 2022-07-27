#include<bits/stdc++.h>
using namespace std;
long long ans;
int n, k;
vector<pair<int, int>> t; // 보물 무게, 가치
vector<int> b; // 가방
priority_queue<int> pq;
int main() { // 보물의 무게와 가방의 무게의 차이가 최소화(가방의 무게보다 커지지 않고 맞을 때까지 보물을 넣는다) 되면 거의 최적화
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		t.push_back({ a,b });
	}
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a; b.push_back(a);
	}
	sort(t.begin(), t.end());
	sort(b.begin(), b.end());
	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && t[idx].first <= b[i]) {
			pq.push(t[idx].second);
			idx++;
		}
		if (pq.size()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}