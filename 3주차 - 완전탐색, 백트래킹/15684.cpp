#include<bits/stdc++.h>
using namespace std;
int n, m, h;
int vis[31][11][11];
int ans = 4;
void go(int idx, int num) { // 나는 vis[a][b][c] 라고 할 때 a번 줄에서 b에서 c로 이동한다고 표현을 했지만 
	//어차피 바로 b에서 b+1로 이동을 하기 때문에 굳이 vis 함수를 3차원으로 할 필요 없이 2차원으로도 풀 수 있음 
	if (num > 3) return;

	int flag = 0;
	for (int i = 1; i <= n; i++) {
		int t = i;
		for (int j = 1; j <= h; j++) {
			if (t != n && vis[j][t][t + 1]) {
				t = t + 1;
			}
			else if (t != 1 && vis[j][t][t - 1]) {
				t = t - 1;
			}
		}
		if (t != i) {
			flag = 1;
			break;
		}
	}
	if (!flag) {
		ans = min(ans, num);
		return;
	}

	for (int i = idx; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (vis[i][j][j + 1] || vis[i][j + 1][j]) continue;
			if (j != 1 && vis[i][j - 1][j]) continue;
			if (j != n - 1 && vis[i][j + 1][j + 2]) continue;
			vis[i][j][j + 1] = 1;
			vis[i][j + 1][j] = 1;
			go(i, num + 1);
			vis[i][j][j + 1] = 0;
			vis[i][j + 1][j] = 0;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		vis[a][b][b + 1] = 1;
		vis[a][b + 1][b] = 1;
	}
	if (m == 0) cout << 0;
	else {
		go(1, 0);
		if (ans != 4) {
			cout << ans;
		}
		if (ans == 4) cout << -1;
	}
}