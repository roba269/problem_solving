#include <cstdio>

const int MAXN = 3005;
int match[MAXN][MAXN];
char buf[MAXN];

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 0 ; i < n ; ++i) {
        scanf("%s", buf);
        for (int j = 0 ; buf[j] ; ++j) {
            if (buf[j] == 'W') {match[i][j] = 1; match[j][i] = -1;}
            else if (buf[j] == 'L') {match[i][j] = -1; match[j][i] = 1;}
            else match[i][j] = match[i][j] = 0;
        }
    }
    while (m--) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1; --v2;
        int cnt = 0;
        for (int i = 0 ; i < n ; ++i) {
            if (match[i][v1] == 1 && match[i][v2] == 1) ++cnt;
        }
        printf("%d\n", n * n - (n - cnt) * (n - cnt));
    }
    return 0;
}