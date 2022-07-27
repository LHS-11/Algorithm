#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;
bool compare(pair<int,int> a,pair<int,int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}
int main() { // 회의 시간을 시작 시간을 우선으로 해서 내림차순 정렬을 하고 앞에서부터 무조건 회의를 실행해서 끝나자마자 가까운 회의를 바로 할 수록 최대 
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	int cnt = 1; int idx = 0;
	sort(v.begin(), v.end(),compare);
	for (int i = 1; i < n;i++) {
		if (v[idx].first >= v[i].second) {
			cnt++;
			idx = i;
		}
	}
	cout << cnt;
}