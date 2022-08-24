#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int a[12][12], cnt[6], vis[11][11];
int ans=INF;
map<int, int>mp;
bool check(int x, int y, int k) {
	for(int i=y;i<y+k;i++){
		for (int j = x; j < x + k; j++) {
			if (!a[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void draw(int x, int y,int k,int t) {
	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
			a[i][j] = t;
		}
	}
}
void go(int x,int y,int n) {

	if (x == 11) { // x 경계 밖에 도착했을 때
		go(1, y + 1, n); // 바로 밑에서 처음부터 탐색
		return;
	}
	if (y == 11) {
		ans = min(ans, n); // y 경계 밖에 도착했을 떄 결과 갱신
		return;
	}
	if (a[y][x] == 0) { // 계속 진행
		go(x + 1, y, n);
		return;
	}
	
	for (int k = 5; k >= 1; k--) {
		if (cnt[k] == 5) continue; // cnt 값이 최대 5개
		if (check(x, y, k)) { // check 값으로 a[y][x]가 1인지 색종이를 붙일 수 있는지 확인
			cnt[k]++; // 색종이 카운팅
			draw(x, y, k, 0); // 색종이 붙여서 0으로 만듦 
			go(x + k, y, n + 1); // 완탐
			draw(x, y, k, 1); 
			cnt[k]--;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<pair<int, int>> q;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> a[i][j];
		}
	}

	go(0, 0, 0);
	if (ans == INF) cout << -1;
	else cout << ans;

}