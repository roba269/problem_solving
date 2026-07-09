#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1e6+5;
int cnt[MAXN];

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1 ; i <= n ; ++i)
            cnt[i] = 0;
        for (int i = 0 ; i < n ; ++i) {
            int tmp;
            scanf("%d", &tmp);
            cnt[tmp]++;
        }
        int ans = 0;
        int last;
        for (int h = 1 ; h <= n ; ++h) {
            if (cnt[h] == 0) continue;
            last = h;
            if (cnt[h] >= 2) ++ans;
        }
        if (cnt[last] == 1) printf("%d\n", ans*2+1);
        else printf("%d\n", ans*2-1);
    }
    return 0;
}