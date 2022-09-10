#include<bits/stdc++.h>
using namespace std;
int n;
double a[10004], ans;
int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	double psum = 1;
	for (int i = 1; i <= n; i++) {
		psum *= a[i]; // i번 인덱스의 값 곱하기
		if (psum < a[i]) { // i번 인덱스까지의 곱이 i번 인덱스의 값보다 작을 때 
			psum = a[i]; // 다시 i번 인덱스부터 값을 곱함
		}
		ans = max(ans, psum);
	}

	printf("%.3lf", ans);
}