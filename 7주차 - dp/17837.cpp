#include<bits/stdc++.h>
using namespace std;
int n, k; // 크기, 말갯수
int a[13][13];
vector<pair<int,int>> vis[13][13];
//vector<pair<int, int>> h[11];
queue<pair<int, int>> q[11];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vis[a-1][b-1].push_back({ i,c-1 });
		q[i].push({ a - 1,b - 1 });
	}

	int cnt = 0;
	while (1) {
		if (cnt > 1000) break;
		if (cnt == 8) break;
		cout << endl;
		cnt++;
		for (int idx = 1; idx <= k; idx++) {
			auto cur = q[idx].front();
			q[idx].pop();
			int x = cur.second;
			int y = cur.first;
			for (int i = 0; i < vis[y][x].size(); i++) {
				if (idx == vis[y][x][i].first) {
					int dir = vis[y][x][i].second;
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[ny][nx] == 2) { // 이동한 곳이 경계 밖이거나 파란색 일때
						dir++; // 방향을 반대로 바꿈
						if (dir == 2) dir = 0; // 왼쪽에서 -> 위로 갈때 방향을 다시 오른쪽으로 초기화 
						else if(dir == 4) dir = 2; // 아래에서 -> dir=4가 되면 방향을 다시 위쪽 방향으로 초기화
						nx = x + dx[dir]; // 이동
						ny = y + dy[dir]; // 이동
						if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[ny][nx] == 2) { // 다시 이동한 곳이 경계 밖이거나 파란색 일때
							nx = x;
							ny = y;
							q[idx].push({ y,x }); // q에다가 원래 위치 넣기
							continue;
						}
					}
					int b = 0;
					if (a[ny][nx] == 1) { //빨간색일때
						for (int k = vis[y][x].size() - 1; k >= i; k--) {
							if(idx==vis[y][x][k].first) vis[ny][nx].push_back({ vis[y][x][k].first,dir });
							else vis[ny][nx].push_back({ vis[y][x][k].first,vis[y][x][k].second });
							if(q[vis[y][x][k].first].size()) q[vis[y][x][k].first].pop();
							q[vis[y][x][k].first].push({ ny,nx });
							b++;
						}
					}
					else if(a[ny][nx]==0){
						for (int k = i; k < vis[y][x].size(); k++) {
							if (idx == vis[y][x][k].first) vis[ny][nx].push_back({ vis[y][x][k].first,dir });
							else vis[ny][nx].push_back({ vis[y][x][k].first,vis[y][x][k].second });
							if (q[vis[y][x][k].first].size()) q[vis[y][x][k].first].pop();
							q[vis[y][x][k].first].push({ ny,nx });
							b++;
						}
					}
					if (!(nx ==x && ny==y)) while (b--) if (vis[y][x].size()) vis[y][x].pop_back();
				}
					//cout << 4 << endl;
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (vis[i][j].size()) cout << vis[i][j].size() << ' ';
					else cout << 0 << ' ';
					if (vis[i][j].size() >= 4) {
						cout << cnt;
						return 0;
					}
				}
				cout << endl;
			}
		}
	}
	cout << -1;
}