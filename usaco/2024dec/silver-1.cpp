#include <cstdio>

typedef long long LL;
const int MAXN = 5e5 + 10;
int a[MAXN], n;
LL L[MAXN], R[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        LL tot = 0;
        for (int i = 1 ; i <= n ; ++i) {
            scanf("%d", &a[i]);
            tot += a[i];
        }
        L[0] = 0;
        for (int i = 1 ; i <= n ; ++i) {
            L[i] = L[i-1] + a[i];
        }
        R[n+1] = 0;
        for (int i = n ; i >= 1 ; --i) {
            R[i] = R[i+1] + a[i];
        }
        LL best = 0;
        for (int left = 0 ; left <= n / 2 - 1 ; left++) {
            int right = n / 2 - 1 - left;
            LL v = L[left] + R[n-right+1];
            if (v > best) best = v;
        }
        printf("%lld %lld\n", tot-best, best);
    }
    return 0;
}