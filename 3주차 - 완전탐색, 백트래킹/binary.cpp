#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int n, vis[17],flag;
vector<int> v, s;
void go(int k) {

	if (n == v.size()) {
		for (auto c : v) {
			cout << c;
		}
		cout << endl;
		return;
	}

	flag = -1;
	for (int i = 0; i < n; i++) {
		if (vis[i] || flag==s[i]) continue;
		vis[i] = 1;
		v.push_back(s[i]);
		go(k + 1);
		flag = s[i];
		v.pop_back();
		vis[i] = 0;
		
 	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n / 2; i++) s.push_back(0);
	for (int i = 0; i < n / 2; i++) s.push_back(1);

	go(0);


}