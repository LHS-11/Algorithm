#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<double,vector<double>,greater<double>> pq;
int main() { // n이 백만개이기 때문에 sort 못씀
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	while (n--) {
		double x;
		cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < 7; i++) {
		//cout.precision(3);
		//cout << fixed<<pq.top() << '\n';
		printf("%.3lf\n", pq.top());
		pq.pop();
	}
}