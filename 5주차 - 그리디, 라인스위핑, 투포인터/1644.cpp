#include<bits/stdc++.h>
using namespace std;
int n, sum, ans;
priority_queue<int, vector<int>, greater<int>>pq;
int chk[4000001];
vector<int> go(int num) { // 2부터~ 각각의 배수를 계속해서 지워나가는 알고리즘
	vector<int> v;
	for (int i = 2; i <= num; i++) {
		if (chk[i]) continue;
		for (int j = 2 * i; j <= num; j += i) {
			chk[j] = 1;
		}
	}
	for (int i = 2; i <= num; i++) 
		if (!chk[i]) v.push_back(i);
	return v;
}
bool check(int n) { // 소수는 나눠지는게 자기자신과 1밖에 없어야함 
	if (n == 1) return 0;
	else if (n == 2) return 1;
	else if (n % 2 == 0) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int main() { // n이 천만 이상이라면 일일이 check 함수를 돌려야함 but 시간이 많이듦
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> v = go(n);
	//for (auto c : v) {
	//	pq.push(c);
	//	sum += c;
	//	while (sum > n) {
	//		sum -= pq.top();
	//		pq.pop();
	//	}
	//	if (sum == n) ans++;
	//}
	for (int i = 1; i <= n; i++) {
		if (check(i)) {
			pq.push(i);
			sum += i;
			while (sum > n) {
				sum -= pq.top();
				pq.pop();
			}
			if (sum == n) ans++;
		}
	}
	cout << ans;
}