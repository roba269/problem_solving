#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 505;
int a[MAXN][MAXN];
int sum[MAXN][MAXN];

int main() {
    int n, k, q;
    scanf("%d%d",&n,&k);
    scanf("%d", &q);
    int best = 0;
    while (q--) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        int delta = w - a[x][y];
        a[x][y] = w;
        for (int i = max(1, x-k+1) ; i <= x ; ++i)
            for (int j = max(1, y-k+1) ; j <= y ; ++j) {
                sum[i][j] += delta;
                if (sum[i][j] > best) best = sum[i][j];
            }
        printf("%d\n", best);
    }
    return 0;
}