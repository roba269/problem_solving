#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN];

int main() {
    int n, q;
    scanf("%d%d",&n,&q);
    for (int i = 0 ; i < n ; ++i) {
        scanf("%d", &a[i]);
        if (i > 0 && a[i] > a[i-1] * 2)
            a[i] = a[i-1] * 2;
    }
    while (q--) {
        int v;
        scanf("%d", &v);
        long long ans = -1, acc = 0;
        for (int i = min(n-1, 30) ; i >= 0 ; --i) {
            long long fullcost = ((long long)v + (1<<i) - 1) / (1 << i) * a[i];
            if (ans == -1 || acc + fullcost < ans) {
                ans = acc + fullcost;
            }
            acc += (long long)a[i] * (v>>i);
            v %= (1<<i);
        }
        cout << ans << endl;
    }
    return 0;
}