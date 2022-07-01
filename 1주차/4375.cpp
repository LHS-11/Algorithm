#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (cin >> n) {
		int cnt = 1;
		int num = 1;
		while (1) {
			if (num % n == 0) {
				break;
			}
			else {
				num = 10 * num +1;
				num %= n;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
}
