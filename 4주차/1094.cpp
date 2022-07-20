#include<bits/stdc++.h>
using namespace std;
int x;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> x;

	int cnt = 0;
	while (x != 0) {
		x % 2 == 1 ? cnt += 1 : cnt;
		x /= 2;
	}
	cout << cnt;
}