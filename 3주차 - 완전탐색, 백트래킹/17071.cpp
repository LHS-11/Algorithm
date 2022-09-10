#include<bits/stdc++.h>
using namespace std;
int n, k;
int vis[500001][2]; // vis[거리][시간] -> 짝홀로 나눠서 , 수빈이가 짝수번(홀수번) 시간에서 동생보다 먼저 방문했다면 무조건 동생과 만날 수가 있음
// 예를 들어 수빈이가 4초 후에 10에 도착했고 동생이 4초 이후의 짝수번대에서 도착한다고 가정하면 수빈이는 계속해서 -1,1을 반복하면 동생과 만남
int go(int n) {
	int dis = n * (n + 1) / 2;
	return dis + k;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	memset(vis, -1, sizeof(vis));
	vis[n][0] = 0;
	queue<pair<int, int>> q;
	q.push({ n,0 });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int nx : {cur.first - 1, cur.first + 1, cur.first * 2}) {
			if (nx < 0 || nx>500000)continue;
			if (vis[nx][(cur.second+1) % 2] < 0) {
				vis[nx][(cur.second + 1) % 2] = cur.second+1;
				q.push({ nx,cur.second + 1 });
			}
		}
	}
	
	for (int i = 0; i <= 500000; i++) {
		int nk = go(i);
		if (nk > 500000) { // 동생이 제한거리를 넘었을 때
			cout << -1;
			break;
		}
		if (vis[nk][i % 2] !=-1 && vis[nk][i%2]<=i) { // 동생보다 수빈이가 동시에 같이 방문하거나, 수빈이가 먼저 방문을 했을 때
			cout << i;
			break;
		}
	}

	return 0;
}