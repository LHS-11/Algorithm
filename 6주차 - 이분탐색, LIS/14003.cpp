#include<bits/stdc++.h>
using namespace std;
int n, lis[1000004], len, a[1000004];
vector<pair<int, int>>v;
vector<int> v1;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		auto idx = lower_bound(lis, lis + len, a[i]);
		int pos = idx - lis;
		if (*idx == 0) len++;
		*idx = a[i];
		v.push_back({ pos,a[i] }); // lis의 idx번호와 값을 저장
	}
	cout << len << '\n';
	for (int i = v.size() - 1; i >= 0; i--) {
		if (len - 1 == v[i].first) { 
			v1.push_back(v[i].second); 
			len--;
		}
	}
	for (int i = v1.size() - 1; i >= 0; i--) cout << v1[i] << ' ';
}