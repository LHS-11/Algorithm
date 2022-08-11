#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q;
int main() {

	cin >> n;

	q = sqrt(n);

	if ((q * q) < n) {
		q++;
	}
	cout << q;
}
