#include <cstdio>

const int MAXN = 7510;
int a[MAXN], b[MAXN];
int left[MAXN], right[MAXN];
int mid[MAXN][MAXN];
int ans[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++i)
        scanf("%d", &a[i]);
    for (int i = 1 ; i <= n ; ++i)
        scanf("%d", &b[i]);
    for (int i = 1 ; i <= n ; ++i) {
        left[i] = left[i-1] + (a[i] == b[i]);
    }
    for (int i = n ; i >= 1 ; --i) {
        right[i] = right[i+1] + (a[i] == b[i]);
    }
    for (int i = 1 ; i <= n ; ++i) {
        mid[i][i] = (a[i] == b[i]);
        for (int len = 1 ; i - len >= 1 && i + len <= n ; len++) {
            int L = i - len, R = i + len;
            mid[L][R] = mid[L+1][R-1] + (a[L] == b[R]) + (a[R] == b[L]);
        }
    }
    for (int i = 1 ; i + 1 <= n ; ++i) {
        mid[i][i+1] = (a[i] == b[i+1]) + (a[i+1] == b[i]);
        for (int len = 1 ; i - len >= 1 && i + 1 + len <= n ; ++len) {
            int L = i - len, R = i + 1 + len;
            mid[L][R] = mid[L+1][R-1] + (a[L] == b[R]) + (a[R] == b[L]);
        }
    }
    for (int L = 1 ; L <= n ; ++L)
        for (int R = L ; R <= n ; ++R) {
            int tmp = left[L-1] + right[R+1] + mid[L][R];
            ++ans[tmp];
        }
    for (int i = 0 ; i <= n ; ++i)
        printf("%d\n", ans[i]);
    return 0;
}