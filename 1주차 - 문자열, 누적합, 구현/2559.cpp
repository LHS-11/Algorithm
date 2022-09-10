#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
int n, k;
int arr[100001];
int sumfix[100001];
int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sumfix[0] = arr[0];
	for (int i = 1; i < n; i++) {
		sumfix[i] += arr[i] + sumfix[i - 1];
	}

	int mx = -INF;
	mx = max(mx, sumfix[k - 1]);
	for (int i = 0; i < n; i++) {
		if (i + k >= n) break;
		mx = max(mx, sumfix[i + k] - sumfix[i]); // sumfix[2]-sumfix[0], sumfix[3]-sumfix[1], ... , sumfix[n-1]-sumfix[n-3] 
	}
	cout << mx;
}
