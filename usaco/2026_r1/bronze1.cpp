#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long a, b, ca, cb, fa;
        cin >> a >> b >> ca >> cb >> fa;
        a += b / cb * ca;
        b %= cb;
        if (a >= fa) {
            cout << 0 << endl;
            continue;
        }
        if (ca <= cb) {
            long long need_a = fa - 1 - a;
            long long num_swap = need_a / ca;
            long long ka = need_a % ca;
            long long kb = num_swap * cb + (cb - 1) - b;
            cout << ka + kb + 1 << endl;
        } else {
            long long ka = fa - 1 - a;
            long long kb = cb - 1 - b;
            cout << ka + kb + 1 << endl;
        }
    }
    return 0;
}