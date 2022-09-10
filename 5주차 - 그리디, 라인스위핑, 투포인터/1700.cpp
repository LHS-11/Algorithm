#include<bits/stdc++.h>
using namespace std;
int n, k;  // 구멍개수, 사용횟수
vector<int> v; // 사용순서
vector<int> c;
int ans, vis[104];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < v.size(); i++) {
		if (!vis[v[i]]) { // 콘센트가 다 꽂혀 있고 꽂혀 있는 용품 중 하나를 빼야함 
			if (c.size() == n) {
				int lastIdx = 0,pos;
				for (auto x : c) {
					int idx = 1000;
					for (int j = i + 1; j < v.size(); j++) {
						if (v[j] == x) {
							idx = j; break;
						}
					}
					if (lastIdx < idx) { // 최종적으로 idx=1000일 경우, 콘센트에 꽂혀 있는 용품 중에 다시 사용해야 하는 용품이 없음
						lastIdx = idx;   // 최종적으로 idx!=1000일 경우, 콘센트에 꽂혀 있는 용품이 다 사용이 될 때, 제일 마지막으로 사용되는 용품을 빼야함
						pos = x;
					}
				}
				ans++;
				vis[pos] = 0;
				c.erase(find(c.begin(), c.end(), pos));
			}
			vis[v[i]] = 1;
			c.push_back(v[i]);
		}
	}
	cout << ans;
}