#include<bits/stdc++.h>
using namespace std;
int n, m, k; // nxn , m개의 나무 , k년
int vis[11][11];
vector<int> v[11][11];
int a[11][11],b[11][11];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z; // 세로, 가로
		v[x][y].push_back(z);
	}
	
	fill(&a[0][0], &a[0][0] + 11 * 11, 5);

	for (int i = 0; i < k; i++) {

		vector <tuple<int, int, int>>v2;

		// 봄
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cnt = 0;
				sort(v[i][j].begin(), v[i][j].end());
				for (int k = 0; k < v[i][j].size(); k++) {
					if (a[i][j] >= v[i][j][k]) {
						a[i][j] -= v[i][j][k];
						v[i][j][k]++; // 양분을 먹고 한살 더 나이를 먹음
					}
					else {
						cnt++; // 정렬을 했기 때문에 이 나무 뒤로 양분이 없어 죽는 나무들을 카운팅
						v2.push_back({ j,i,v[i][j][k] }); // 양분이 없어 죽은 나무들
					}
				}
				while(cnt--) v[i][j].pop_back(); // 죽은 나무들을 벡터에서 pop 
			}
		}

		// 여름
		for(int i=0;i<v2.size();i++) {
			int x, y, z;
			tie(x, y, z) = v2[i];
			a[y][x] += (z / 2);
		}

		// 가을 - 번식
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int t = 0; t < v[i][j].size(); t++) {
					if (v[i][j][t] % 5 == 0) {
						if (j - 1 >= 1 && i - 1 >= 1) v[i - 1][j - 1].push_back(1);
						if (j - 1 >= 1) v[i][j - 1].push_back(1);
						if (j - 1 >= 1 && i + 1 <= n) v[i + 1][j - 1].push_back(1);
						if (i - 1 >= 1) v[i - 1][j].push_back(1);
						if (i + 1 <= n) v[i + 1][j].push_back(1);
						if (j + 1 <= n && i - 1 >= 1) v[i - 1][j + 1].push_back(1);
						if (j + 1 <= n) v[i][j + 1].push_back(1);
						if (j + 1 <= n && i + 1 <= n) v[i + 1][j + 1].push_back(1);
					}
				}
			}
		}

		// 겨울
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] += b[i][j];
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n; j++) {
			sum += v[i][j].size();
		}
	}
	cout << sum << '\n';
}