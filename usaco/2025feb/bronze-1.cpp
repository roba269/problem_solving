#include <cstdio>

const int MAXN = 2010;
char buf[MAXN][MAXN];
int cnt[MAXN/2][MAXN/2];

inline int get_score(int v) {
    if (v <= 2) return v;
    return 4 - v;
}

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 0 ; i < n ; ++i) {
        scanf("%s", buf[i]);
    }
    int tot = 0;
    for (int i = 0 ; i < n/2 ; ++i)
        for (int j = 0 ; j < n/2 ; ++j) {
            if (buf[i][j] == '#') ++cnt[i][j];
            if (buf[n-1-i][j] == '#') ++cnt[i][j];
            if (buf[i][n-1-j] == '#') ++cnt[i][j];
            if (buf[n-1-i][n-1-j] == '#') ++cnt[i][j];
            tot += get_score(cnt[i][j]);
        }
    printf("%d\n", tot);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        int tx = x, ty = y;
        if (tx >= n / 2) tx = n - 1 - tx;
        if (ty >= n / 2) ty = n - 1 - ty;
        if (buf[x][y] == '.') {
            buf[x][y] = '#';
            tot -= get_score(cnt[tx][ty]);
            ++cnt[tx][ty];
            tot += get_score(cnt[tx][ty]);
        } else {
            buf[x][y] = '.';
            tot -= get_score(cnt[tx][ty]);
            --cnt[tx][ty];
            tot += get_score(cnt[tx][ty]);
        }
        printf("%d\n", tot);
    }
    return 0;
}