#include <cstdio>

const int MAXN = 2e5 + 10;
char buf[MAXN];
char ans[MAXN];

int main() {
    int T, k, n;
    scanf("%d%d",&T,&k);
    while (T-- ) {
        scanf("%d%s", &n, buf);
        printf("YES\n");
        if (k == 1) {
            bool flip = false;
            for (int i = n - 1 ; i >= 0 ; --i) {
                if (!flip) ans[i] = buf[i];
                else {ans[i] = (char)((int)'M' + 'O' - buf[i]);}
                if (ans[i] == 'O') flip = !flip;
            }
            ans[n] = 0;
            printf("%s\n", ans);
        }
    }
    return 0;
}