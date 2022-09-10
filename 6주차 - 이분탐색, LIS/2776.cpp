#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t;
vector<int> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		cin >> m;
		while (m--) {
			int x;
			cin >> x;
			// lower_bound는 찾으려는 원소와 같은 값을 찾고, 없다면 그 값 바로 이상의 값을 찾는다
			// 찾으려는 원소가 맨 마지막 원소였다면 end()를 출력함으로 해당 값이 나올 경우 0을 출력하고
			// 찾으려는 원소가 맨 마지막 원소가 아니라면 바로 그 이상의 값을 출력함으로 그 위치에 해당하는 값이 x인지를 확인한다. 
			if (lower_bound(v.begin(), v.end(), x) == v.end() || *lower_bound(v.begin(), v.end(), x) != x) cout << 0 << '\n';
			else cout << 1 << '\n';
		}
		v.clear();
	}
}