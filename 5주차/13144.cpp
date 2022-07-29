#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int vis[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (pq.size() && vis[x] == 1) {
			vis[pq.top().second] = 0;
			pq.pop();
		}
		pq.push({ i,x });
		vis[x] = 1;

		if (pq.size()) ans += pq.size();
	}
	cout << ans;
}