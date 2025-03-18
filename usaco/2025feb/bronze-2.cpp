#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 2e5+10;
int cnt[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i) {
        int t;
        scanf("%d", &t);
        ++cnt[t];
    }
    int c0 = 0;
    for (int i = 0 ; i <= n ; ++i) {
        printf("%d\n", max(cnt[i], c0));
        if (cnt[i] == 0) ++c0;
    }
    return 0;
}