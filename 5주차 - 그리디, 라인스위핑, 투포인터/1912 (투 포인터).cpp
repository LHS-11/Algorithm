#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	int en = 0;
	int sum = v[en];
	int ans = -1001;
	ans = max(ans, sum); // 처음 인덱스가 0을 포함하는 연속합부터 시작
	for (int st = 0; st < v.size(); st++) {
		if (st > en) {
			en = st;
			sum = v[en];
			ans = max(ans, sum);
		}
		while (sum > 0 && en >= st && en < v.size()-1) { // 그 전의 연속합이 음수라면 그 다음의 연속합을 구하는 것보다 새롭게 인덱스를 조정하는게 더 큼
			en++;
			sum += v[en];
			ans = max(ans, sum);
		}
		sum -= v[st];
	}
	cout << ans;
}