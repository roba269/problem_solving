#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1e6+10;
int a[MAXN];
int left[MAXN];
int right[MAXN][2];
int uni[MAXN];
int vis[MAXN];
int n;

int main() {
    memset(left, -1, sizeof(left));
    memset(right, -1, sizeof(right));
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0 ; i < n ; ++i) {
        scanf("%d", &a[i]);
        if (left[a[i]] == -1) left[a[i]] = i;
        if (vis[a[i]] == 0) {
            vis[a[i]] = 1;
            ++cnt;
        }
        uni[i] = cnt;
    }
    for (int i = n-1 ; i >= 0 ; --i) {
        if (right[a[i]][0] == -1) right[a[i]][0] = i;
        else if (right[a[i]][1] == -1) right[a[i]][1] = i;
    }
    long long ans = 0;
    for (int i = 1 ; i <= n ; ++i) {
        if (right[i][1] == -1) continue;
        if (right[i][1] == 0) continue;
        ans += uni[right[i][1]-1] - (left[i] < right[i][1]);
    }
    printf("%lld\n", ans);
    return 0;
}