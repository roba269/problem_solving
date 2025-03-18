#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 5e5+10;
int a[MAXN], b[MAXN];
vector<int> up[MAXN], down[MAXN];
int n;

LL lsum[MAXN], rsum[MAXN];
LL solve(const vector<int> &up, const vector<int> &down) {
    for (int i = 0 ; i < down.size() ; ++i) {
        if (i == 0) lsum[i] = down[i] + 1;
        else lsum[i] = lsum[i-1] + down[i] + 1;
    }
    for (int i = down.size() - 1 ; i >= 0 ; --i) {
        if (i == down.size() - 1) rsum[i] = n - down[i];
        else rsum[i] = rsum[i+1] + (n - down[i]);
    }
    LL res = 0;
    for (auto x : up) {
        int L = min(x, n-x-1), R = max(x, n-x-1);
        int itr1 = lower_bound(down.begin(), down.end(), L) - down.begin();
        int itr2 = upper_bound(down.begin(), down.end(), R) - down.begin();
        int diff = itr2 - itr1;
        res += (LL)diff * (min(x, n-x-1) + 1);
        if (itr1 > 0) res += lsum[itr1-1];
        if (itr2 < down.size()) res += rsum[itr2];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i)
        scanf("%d", &a[i]);
    for (int i = 0 ; i < n ; ++i)
        scanf("%d", &b[i]);
    
    LL ans = 0;
    int cur = 0;
    for (int i = 0 ; i < n-1 ; ++i) {
        //if (a[i] == b[i]) ++cur;
        //ans += (LL)cur * (n-i) * (n-i-1) / 2;
        if (a[i] == b[i]) ans += (LL)(n-i) * (n-i-1) / 2;
    }
    //printf("after left scan: %lld\n", ans);

    cur = 0;
    for (int i = n-1 ; i > 0 ; --i) {
        //if (a[i] == b[i]) ++cur;
        //ans += (LL)cur * (i+1) * i / 2;
        if (a[i] == b[i]) ans += (LL)(i+1) * i / 2;
    }
    //printf("after right scan: %lld\n", ans);

    for (int i = 0 ; i < n ; ++i) {
        up[a[i]].push_back(i);
        down[b[i]].push_back(i);
    }
    //printf("begin ans: %lld\n", ans);
    for (int v = 1 ; v <= n ; ++v) {
        if (up[v].empty() || down[v].empty()) continue;
        ans += solve(up[v], down[v]);
        //printf("after %d: %lld\n", v, ans);
    }
    printf("%lld\n", ans);
    return 0;
}