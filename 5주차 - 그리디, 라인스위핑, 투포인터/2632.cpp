#include<bits/stdc++.h>
using namespace std;
int n, m, sum;
int a[1004];
int b[1004];
int psumA[2020];
int psumB[2020];
map<int, int> m1;
map<int, int>m2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> sum >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psumA[i] = psumA[i - 1] + a[i];
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		psumA[i] = psumA[i - 1] + a[i - n];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		psumB[i] = psumB[i - 1] + b[i];
	}
	for (int i = m + 1; i <= 2 * m; i++) {
		psumB[i] = psumB[i - 1] + b[i - m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n + i; j++) {
			m1[psumA[j] - psumA[j - i - 1]]++; // i => 0 일때 (차이가 0)
			if (i == n-1) break;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j <= m + i; j++) {
			m2[psumB[j] - psumB[j - i - 1]]++;
			if (i == m-1) break;
		}
	}

	int ans = 0;
	m1[0] = 1;
	m2[0] = 1;
	for (int i = 0; i <= sum; i++) {
		ans += (m1[i] * m2[sum - i]);
	}
	cout << ans;
}