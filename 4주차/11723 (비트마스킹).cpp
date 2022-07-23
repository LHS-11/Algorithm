#include<bits/stdc++.h>
using namespace std;
int m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m;

	int bit=0;
	while (m--) {
		string s;
		cin >> s;

		if (s == "add") {
			int n;
			cin >> n;
			bit |= (1 << n); // or 연산자로 n번째 인덱스를 무조건 1로 만듦
		}
		else if (s == "check") {
			int n;
			cin >> n;
			if (bit & (1 << n)) { // and 연산자로 n번째 인덱스가 켜져있는지 확인
				cout << 1 << '\n';
			}
			else cout << 0 << '\n';
		}
		else if (s == "remove") {
			int n;
			cin >> n;
			bit &= ~(1 << n); // not 연산자로 n번째 인덱스를 역으로 치환하고 and 연산자 이용
		}
		else if (s == "toggle") {
			int n;
			cin >> n;
			bit ^= (1 << n); // xor 연산자 서로 toggle
		}
		else if (s == "all") {
			bit = (1 << 21) - 1; // n의 집합의 모든 비트 켜기
		}
		else if (s == "empty") {
			bit = 0; 
		}
	}
}