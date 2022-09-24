#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int n, ans;
vector <int> v;
int sumfix[404];
vector<tuple<int, int, int>>v1;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		ans = max(x, ans);
		sumfix[i + 1] = x;
	}

	for (int i = 2; i <= n; i++) {
		sumfix[i] = v[i - 1] + sumfix[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			v1.push_back({ i,j,sumfix[j] - sumfix[i - 1] });
		}
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v1.size(); i++) {
		int x, y, z;
		tie(x, y, z) = v1[i];
		for (int j = i + 1; j < v1.size(); j++) {
			int nx, ny, nz;
			tie(nx, ny, nz) = v1[j];

			if (y < nx) {
				if (z == nz) {
					int sum = sumfix[ny] - sumfix[x - 1];
					ans = max(ans, sum);
				}

			}
		}
	}
	cout << ans << '\n';


}