#include<bits/stdc++.h>
using namespace std;
int k;
vector<int>n;
vector<int> ans[11];
void go(int a, int b,int depth) {

	if (depth==1) {
		ans[depth].push_back(n[a]);
		return;
	}
	ans[depth].push_back(n[(b + a) / 2]);
	go(a, (b + a) / 2-1,depth-1);
	go((b + a) / 2 + 1,b, depth-1);
	return;

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k;
	for (int i = 0; i < pow(2, k)-1; i++) {
		int x;
		cin >> x;
		n.push_back(x);
	}
	go(0, pow(2, k) - 2,k);
	for (int i = k; i >= 1; i--) {
		for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << ' ';
		cout << '\n';
	}
}