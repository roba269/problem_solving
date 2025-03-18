#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 2e5+10;
unordered_set<int> mp[MAXN];
LL ans[MAXN];
int n;

class DSU {
public:
    int sz[MAXN];
    int fa[MAXN];
    void init(int n) {
        for (int i = 0 ; i < n ; ++i) {
            fa[i] = i; sz[i] = 1;
        }
    }
    int find(int p) {
        if (p == fa[p]) return p;
        return fa[p] = find(fa[p]);
    }
    void unite(int u, int v) {
        int p1 = find(u);
        int p2 = find(v);
        if (p1 != p2) {
            if (sz[p1] > sz[p2]) swap(p1, p2);
            fa[p1] = p2;
            sz[p2] += sz[p1];
        }
    }
} dsu;
vector<int> comp[MAXN];

int fa[MAXN], cnt[MAXN];
int findp(int p) {
    if (p == fa[p]) return p;
    return fa[p] = findp(fa[p]);
}
void uni(int i, int j, LL &ans) {
    int v1 = findp(i), v2 = findp(j);
    if (v1 != v2) {
        fa[v1] = v2;
        ans -= (LL)cnt[v2] * (cnt[v2] - 1) / 2;
        cnt[v2] += cnt[v1];
        ans += (LL)cnt[v2] * (cnt[v2] - 1) / 2;
        ans -= (LL)cnt[v1] * (cnt[v1] - 1) / 2;
        cnt[v1] = 0;
    }
}

void solve() {
    for (int i = 1 ; i <= n ; ++i) {
        fa[i] = i;
        cnt[i] = 1;
    }
    LL cur = 0;
    ans[n-1] = cur;
    for (int i = n - 1 ; i >= 1 ; --i) {
        for (auto j : mp[i]) {
            if (j > i) uni(i, j, cur);
        }
        ans[i-1] = cur;
    }
}

int main() {
    int m;
    char buf[MAXN];
    scanf("%d%d",&n,&m);
    scanf("%s", buf);
    while (m--) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        mp[t1].insert(t2);
        mp[t2].insert(t1);
    }
    
    dsu.init(n+1);
    for (int i = 1 ; i <= n ; ++i) {
        if (buf[i-1] == '1') {
            //int first = -1;
            for (auto j : mp[i]) {
                if (j < i) continue;
                dsu.unite(i, j);
                //if (first == -1) first = j;
                //else dsu.unite(first, j);
            }
        }
    }
    
    for (int i = 1 ; i <= n ; ++i) {
        comp[dsu.find(i)].push_back(i);
    }
    for (int i = 1 ; i <= n ; ++i) {
        if (comp[i].size() <= 1) continue;
        /*
        for (int j = 0 ; j < comp[i].size() - 1 ; ++j) {
            mp[comp[i][j]].insert(comp[i][j+1]);
            mp[comp[i][j+1]].insert(comp[i][j]);
        }
        */
        for (int j = 0 ; j < comp[i].size() ; ++j) {
            for (int k = j+1 ; k < comp[i].size() ; ++k) {
                int t1 = comp[i][j], t2 = comp[i][k];
                mp[t1].insert(t2);
                mp[t2].insert(t1);
            }
        }
    }
    /*
    printf("=======\n");
    for (int i = 1 ; i <= n ; ++i) {
        printf("%d: ", i);
        for (auto j: mp[i]) {
            printf(" %d", j);
        }
        printf("\n");
    }
    printf("========\n");
    */
    solve();
    for (int i = 0 ; i < n ; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}