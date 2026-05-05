#include <cstdio>
using namespace std;

const int MAXN = 3e5 + 10;
char buf[MAXN];
int ans[MAXN];

int main() {
    int T, k, n;
    scanf("%d%d",&T,&k);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", buf);
        if (n % 2) {
            printf("-1\n");
            continue;
        }
        bool flg = true;
        for (int i = 0 ; i < n * 3 / 2 ; ++i) {
            if (buf[i] != buf[i+n*3/2]) {flg = false; break;}
        }
        if (flg) {
            printf("1\n");
            for (int i = 0 ; i < n * 3 ; ++i) {
                if (i) printf(" ");
                printf("1");
            }
            printf("\n");
            continue;
        }

        for (int i = 0 ; i < n * 3 / 2 ; i += 3) {
            int j = i + n * 3 / 2;
            if (buf[i] == buf[j]) {
                ans[i] = ans[i+1] = ans[i+2] = ans[j] = ans[j+1] = ans[j+2] = 1;
                continue;
            }
            if (buf[i] == 'C' && buf[j] == 'W' || buf[i] == 'O' && buf[j] == 'C' || buf[i] == 'W' && buf[j] == 'O') {
                ans[i] = ans[i+1] = 1; ans[i+2] = 2;
                ans[j] = 2; ans[j+1] = ans[j+2] = 1;
            } else {
                ans[i] = 1; ans[i+1] = ans[i+2] = 2;
                ans[j] = ans[j+1] = 2; ans[j+2] = 1;
            }
        }
        printf("2\n");
        for (int i = 0 ; i < n * 3 ; ++i) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}