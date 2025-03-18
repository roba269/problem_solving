#include <cstdio>
using namespace std;

const int MAXN = 5e5 + 10;
const int MOD = 1e9 + 7;
char buf[MAXN];
int ans[MAXN];
int n;
int nextr[MAXN];

void process_bseg() {
    int cur = n;
    for (int i = n-1 ; i >= 0 ; --i) {
        if (buf[i] == 'R') cur = i;
        else nextr[i] = cur;
    }
}

inline bool ok(int st, int len) {
    return (nextr[st+len] >= st + len + len);
}

int main() {
    scanf("%d%s", &n, buf);
    process_bseg();
    ans[0] = 1;
    for (int i = 0 ; i < n ; ++i) {
        if (buf[i] == 'X') {
            ans[i+1] = (ans[i+1] + ans[i]) % MOD;
        }
        for (int x = 1 ; i+x+x <= n ; ++x) {
            if (buf[i+x-1] == 'B') break;
            if (ok(i, x)) {
                ans[i+x+x] = (ans[i+x+x] + ans[i]) % MOD;
            }
        }
    }
    printf("%d\n", ans[n]);
    return 0;
}