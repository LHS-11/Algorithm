#include<bits/stdc++.h>
using namespace std;
int n, m;
int cnt = 0;
int arr[15004];
int chk[15001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cnt += (upper_bound(arr + i+1, arr + n, m - arr[i]) - lower_bound(arr + i+1, arr + n, m - arr[i]));
	}

	cout << cnt;
}
