#include <cstdio>

const int MAXN = 1010;
int cnt1[MAXN][MAXN], cnt2[MAXN][MAXN], cnt3[MAXN][MAXN];

int main() {
    int n, q, ans = 0;
    scanf("%d%d", &n, &q);
    while (q--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (++cnt1[x][y] == n) ++ans;
        if (++cnt2[x][z] == n) ++ans;
        if (++cnt3[y][z] == n) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}