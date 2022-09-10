#include<bits/stdc++.h>
using namespace std;
int t;
vector<int> v[1001];
int vis[1001];
void dfs(int now) { 

	vis[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int nxt = v[now][i];
		if (vis[nxt]) continue;
		dfs(nxt);
	}
	return;
}
int main() { // tree는 한 노드에서 모든 노드를 방문 가능해야 하고, 사이클이 있으면 안됨 ( 사이클이 있다면 간선이 n개 이상) -> tree일려면 간선의 개수가 n-1개
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		fill(&vis[0], &vis[0] + 1001, 0);
		int n, m;
		cin >> n >> m;
		for(int i=0;i<m;i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			dfs(i);
			cnt++;
		}
		if (cnt == 1 && m == n - 1) cout << "tree"<<'\n';
		else cout << "graph"<<'\n';

	}

}