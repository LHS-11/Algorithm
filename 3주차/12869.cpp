#include<bits/stdc++.h>
using namespace std;
int n;
int scv[3];
int d[6][3] = {
{9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,3,9},{1,9,3} };
int vis[61][61][61];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> scv[i];

	queue<tuple<int, int, int>> q;

	int x, y, z;
	if (!scv[0]) x = 0;
	else x = scv[0];
	if (!scv[1]) y = 0;
	else y = scv[1];
	if (!scv[2]) z = 0;
	else z = scv[2];

	memset(vis, -1, sizeof(vis));
	q.push({ x,y,z });
	vis[x][y][z] = 0;
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		if (x == 0 && y == 0 && z == 0) {
			break;
		}
		for (int i = 0; i < 6; i++) {
			int nx = x - d[i][0];
			if (nx < 0) nx = 0;
			// int nx= max(0,x-d[i][0])으로 대체 가능
			int ny = y - d[i][1];
			if (ny < 0) ny = 0;
			int nz = z - d[i][2];
			if (nz < 0) nz = 0;

			if (vis[nx][ny][nz] < 0) {
				vis[nx][ny][nz] = vis[x][y][z] + 1;
				q.push({ nx,ny,nz });
			}
		}
	}
	cout << vis[0][0][0];
}