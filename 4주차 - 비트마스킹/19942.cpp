#include<bits/stdc++.h>
using namespace std;
int n;
vector<tuple<int, int, int, int,int>> food;
int mp, mf, ms, mv;
int vis[16];
int alp[16];
vector<int>ch;
vector<int>rst;
int ans = 987654321;
void go(int idx,int cnt,int k) {

	if (k == cnt) { 
		int a = 0, b = 0, c = 0, d = 0, cost = 0;
		for (auto x : ch) {
			int q, w, e, r, t;
			tie(q, w, e, r, t) = food[x];
			a += q; b += w; c += e; d += r; cost += t;
		}
		if (a >= mp && b >= mf && c >= ms && d >= mv) { // 조건에 허용 된다면 
			if (ans > cost) { // rst에 최소 비용 식재료 갱신
				ans = cost;
				rst.clear();
				for (auto c : ch) {
					rst.push_back(c);
				}
			}
			else if (ans == cost && !rst.empty()) { // 사전 순으로 가장 빠른 것을 뽑기 위해서 비교
				int flag = 0;
				for (int i = 0; i < rst.size(); i++) {
					if (rst[i] < ch[i]) { //앞에서부터 비교를 하는데 만약 앞에서 이미 rst가 ch보다 작으면 이미 사전순으로 앞
						break;
					}
					else if(rst[i]>ch[i]){
						flag = 1;
						break;
					}
				}
				if (flag) {
					rst = ch;
				}
			}
		}
		return;
	}

	for (int i = idx; i < n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		ch.push_back(i);
		go(i,cnt+1, k);
		vis[i] = 0;
		ch.pop_back();
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++) {
		int p, f, s, v, c;
		cin >> p >> f >> s >> v >> c;
		food.push_back({ p,f,s,v,c });
	}
	for (int i = 1; i <= n; i++){ // 1~n개의 식재료가 있을 때, 식재료 1개만 선택 됐을 때, 2개만 선택 됐을때.... n개까지 선택 됐을때
								// 조합을 이용해서 완탐 돌림
		go(0, 0, i);
	}
	if (rst.empty()) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
		for (auto c : rst) cout << c+1 << ' ';
	}
}
