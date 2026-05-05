#include <cstdio>
#include <algorithm>
using namespace std;

int cnt[20][20][20];

int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    while (k--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        --x; --y; --z;
        if (y > z) swap(y, z);
        ++cnt[x][y][z];
    }
    int best = -1, best_cnt = 0;
    for (int mask = 0 ; mask < (1<<n) ; ++mask) {
        int s = 0;
        for (int x = 0 ; x < n ; ++x) {
            if (!(mask & (1<<x))) continue;
            for (int y = 0 ; y < n ; ++y) {
                if (mask & (1<<y)) continue;
                for (int z = y + 1 ; z < n ; ++z) {
                    if (mask & (1<<z)) continue;
                    s += cnt[x][y][z];
                }
            }
        }
        if (s > best) {
            best = s;
            best_cnt = 1;
        } else if (s == best) {
            ++best_cnt;
        }
    }
    printf("%d %d\n", best, best_cnt);
    return 0;
}