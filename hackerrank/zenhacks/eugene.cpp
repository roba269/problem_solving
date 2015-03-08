#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
LL m;
int dig;

LL pow_mod(LL a, LL b, LL m) {
	LL s = 1;
	while (b) {
		if (b&1) s = s * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return s;
}

int dig_cnt(LL a) {
	if (a < 10) return 1;
	if (a < 100) return 2;
	if (a < 1000) return 3;
	return 4;
}

LL solve(LL a, LL n) {
	if (n == 0) return 0;
	if (n == 1) return a % m;
	LL tmp = solve(a, n/2);
	LL tmp2 = tmp * pow_mod(10, dig * (n/2), m) % m;
	LL res = (tmp + tmp2) % m;
	if (n % 2 == 1) {
		res += a * pow_mod(10, dig * (n-1), m) % m;
		res %= m;
	}
	return res;
}

int main() {
	int T;
	LL a, n;
	cin >> T;
	while (T--) {
		cin >> a >> n >> m;
		dig = dig_cnt(a);
		cout << solve(a, n) << endl;
	}
	return 0;
}

