#include<bits/stdc++.h>
using namespace std;
set<int> st; // set은 애초에 중복으로 값이 들어가지 않는데, all 함수에서 clear 함수를 사용하고 insert를 할 필요가 없었는데, 
			 // 사용했다가 시간초과가 났다. 애초에 clear()의 시간복잡도가 O(n)이기 때문에 은근 시간차이가 남
int n;
void add(int x) {
	st.insert(x);
}
int check(int x) {
	if (st.find(x) != st.end()) return 1;
	else return 0;
}
void remove(int x) {
	st.erase(x);
}
void toggle(int x) {
	if (check(x)) remove(x);
	else st.insert(x);
}
void all() {
	for (int i = 1; i <= 20; i++) st.insert(i);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		if (s == "add") {
			int n;
			cin >> n;
			add(n);
		}
		else if (s == "check") {
			int n;
			cin >> n;
			cout << check(n) << '\n';
		}
		else if (s == "remove") {
			int n;
			cin >> n;
			remove(n);
		}
		else if (s == "toggle") {
			int n;
			cin >> n;
			toggle(n);
		}
		else if (s == "all") {
			all();
		}
		else if (s == "empty") {
			st.clear();
		}
	}
}