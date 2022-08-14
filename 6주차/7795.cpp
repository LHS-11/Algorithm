#include<bits/stdc++.h>
using namespace std;
int t;
int arr1[20004], arr2[20004];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;

	while (t--) {
		int n, m;

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> arr2[i];
		}
		sort(arr1, arr1 + n);
		sort(arr2, arr2 + m);

		int sum = 0;
		for (int i = 0; i < n; i++) { // B를 기준으로 해서 A의 값보다 작은게 있는지 확인 
			sum += lower_bound(arr2, arr2 + m, arr1[i]) - arr2;
		}
		cout << sum << '\n';
	}
}