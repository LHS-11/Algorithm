#include<bits/stdc++.h>
using namespace std;
int n, mp, mf, ms,mv;
vector<tuple<int, int, int, int,int>> food;
int ans = 987654321;
vector<int>rst;
map<int, vector<vector<int>>>m; //2차원 배열을 통해서 cost의 비용을 가진 음식 조합이 123 , 3이 있을 때 그거 자체를 저장하기 위한 이차원 벡터
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	cin>>mp >> mf >> ms >> mv;
	
	for (int i = 0; i < n; i++) {
		int a, b, c, d,e;
		cin >> a >> b >> c >> d>>e;
		food.push_back({ a,b,c,d,e });
	}

	for (int i = 1; i < (1 << n); i++) {
		int p=0, f=0, s=0, v = 0 , cost = 0;
		rst.clear();
		for (int j = 0; j < n; j++) {
			int a, b, c, d, e;
			tie(a, b, c, d, e) = food[j];
			if (i & (1 << j)) {
				rst.push_back(j + 1);
				p += a;
				f += b;
				s += c;
				v += d;
				cost += e;
			}
			if (p >= mp && f >= mf && s >= ms && v >= mv) {
				if (ans >= cost) {
					ans = cost;
					m[ans].push_back(rst);
				}
			}
		}
	}
	if (ans == 987654321) cout << -1;
	else {
		cout << ans << '\n';
		sort(m[ans].begin(), m[ans].end());
		for (auto c : m[ans][0]) {
			cout << c << ' ';
		}
	}
}