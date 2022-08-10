#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int a[10];
int n = 6;
int vis[12];
int ans = 0;
void go(int idx,int cnt,int sz) {
	if (cnt == sz) {
		for (auto c : v) cout << c << ' ';
		cout << endl;
		ans++;
		return;
	}
	for (int i = idx+1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		v.push_back(a[i]);
		go(i,cnt+1, sz);
		v.pop_back();
		vis[i] = 0;
	}
}
void permutation(int cnt, int sz) {
	if (cnt == sz) {
		for (auto c : v) cout << c << ' ';
		cout << endl;
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		v.push_back(a[i]);
		permutation(cnt + 1, sz);
		v.pop_back();
		vis[i] = 0;
	}
}
int main() {
	for (int i = 1; i <= 10; i++) a[i] = i;

	go(0,0, 3);
	cout << ans;
	//permutation(0, 3);
	/*v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	sort(v.begin(), v.end());
	do {
		for (auto c : v) cout << c << ' ';
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));*/
}