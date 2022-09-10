#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int a, b, c, d;
map<pair<int, int>, int> dp;
queue<pair<int, int>> q;
void go(int x, int y,int cnt) {
	if (dp[{x, y}]) return;
	dp[{x, y}] = cnt + 1;
	q.push({ x,y });

}
void bfs(int x,int y) {
	dp[{x, y}] = 1;
	q.push({ x,y });
	while (q.size()) {
		auto cur = q.front();
		q.pop();
		int nx = cur.first;
		int ny = cur.second;

		// fill
		go(a, ny, dp[{nx, ny}]);
		go(nx, b, dp[{nx, ny}]);

		// empty
		go(0, ny, dp[{nx, ny}]);
		go(nx, 0, dp[{nx, ny}]);
	
		//// x-> y
		if (nx + ny > b)  go(nx - (b - ny), b, dp[{nx, ny}]);
		else go(0, nx + ny, dp[{nx, ny}]);

		// y->x
		if (nx + ny > a) go(a, ny - (a - nx), dp[{nx, ny}]);
		else go(nx + ny, 0, dp[{nx, ny}]);
	}
	if (dp[{c, d}]) cout << dp[{c, d}]-1;
	else cout << -1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> a >> b >> c >> d;
	bfs(0, 0);
}