#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 200010;
const int MOD = 1000000007;
char buf[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", buf);
        int ans = 0;
        bool flg = false;
        for (int i = 0 ; buf[i] ; ++i) {
            if (buf[i] > '1') {
                flg = true;
                if ((buf[i] - '0') % 2) buf[i] = '1';
                else buf[i] = '0';
            }
        }
        if (flg) ++ans;

        int tmp = 0;
        for (int i = 0 ; buf[i] ; ++i) {
            tmp = ((long long)tmp * 2 + buf[i] - '0') % MOD;
        }
        ans = (ans + tmp) % MOD;

        tmp = 0;
        for (int i = 0 ; buf[i+1] ; ++i) {
            tmp = ((long long)tmp * 2 + buf[i] - '0') % MOD;
        }
        ans = (ans + tmp) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}