#include<bits/stdc++.h>
using namespace std;
int n, atk;
long long ans = 0;
vector<tuple<int, int, int>> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> atk;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	long long sum = 0;
	for(int i=0;i<n;i++){
		int info, atk1, h; // 정보 , 공격력 ,체력 
		tie(info, atk1, h) = v[i];

		if (info == 1) {
			long long l = 0, r = 1e18+4, mid;
			long long cnt = 1e18;
			while (l <= r) {
				mid = (l + r) >> 1;
				if (mid * atk >= h) {
					cnt = min(cnt, mid);
					r = mid - 1;
				}
				else l = mid + 1;
			}
			sum += (cnt - 1) * atk1;
		}
		else {
			if (ans < sum+1) ans = sum + 1;
			if (sum > h) sum -= h;
			else sum = 0;
			atk += atk1;
		}
	}
	if (ans < sum+1) ans = sum + 1;
	cout << ans;
}
