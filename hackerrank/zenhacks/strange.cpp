#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	long long r, c;
	long long ans;
	cin >> r >> c;
	if (r % 2 == 1) {
		ans = r / 2 * 10 + (c-1) * 2;
	} else {
		ans = (r / 2 - 1) * 10 + c * 2 - 1;
	}
	cout << ans << endl;
	return 0;
}

