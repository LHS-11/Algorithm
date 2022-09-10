#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>>v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int t = 0;
	for (int i = 0; i < n; i++) { //소가 도착했을 때, 검문 받고 있지 않다면 바로 검문 받으면 되고 검문 받고 있다면 끝나자마자 바로 다음 검문을 받음
		if (t > v[i].first) {
			t += v[i].second;
		}
		else {
			t = v[i].first + v[i].second;
		}
	}
	cout << t;
}