#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;
bool cmp(pair<int, int>a, pair<int, int >b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end(), cmp);
	
	priority_queue<int, vector<int>, greater<int>> pq;

	int st = v[0].first; // 처음 끝점
	int en = v[0].second; // 처음 시작점
	pq.push(en);
	int sum = 0;
	for (int i = 1; i < v.size(); i++) {
		if (pq.top() <= v[i].first) { // 만약 겹쳤다면 그 해당 선분을 넣고 시작점 새로 갱신
			pq.push(v[i].second);
		}
		else {
			sum += st - pq.top();
			while (pq.size()) pq.pop();
			pq.push(v[i].second);
			st = v[i].first;
		}
	}
	sum += st - pq.top();
	cout << sum;
}