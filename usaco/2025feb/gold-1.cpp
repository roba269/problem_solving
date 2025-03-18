#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 2e5+10;
const LL LLINF = 1000000000LL * 1000000000LL;
int a[MAXN], c[MAXN];
int n;
bool vis[MAXN], in_cycle[MAXN];
vector<int> rev[MAXN];
LL dp[MAXN][2];
LL dp_cc[MAXN][2];

void find_cycle(int k, vector<int>& ans) {
    while (!vis[k]) {
        vis[k] = true;
        k = a[k];
    }
    ans.clear();
    ans.push_back(k);
    int tmp = a[k];
    while (tmp != k) {
        ans.push_back(tmp);
        tmp = a[tmp];
    }
}

void tree_dp(int root) {
    vis[root] = true;
    dp[root][0] = 0;
    dp[root][1] = c[root];
    for (auto ch : rev[root]) {
        if (in_cycle[ch]) continue;
        tree_dp(ch);
        dp[root][0] += dp[ch][1];
        dp[root][1] += min(dp[ch][0], dp[ch][1]);
    }
}

void try_cycle(int start, int cur) {
    dp_cc[cur][0] = dp[cur][0];
    dp_cc[cur][1] = dp[cur][1];
    int next = a[cur];
    if (next == start) return;
    try_cycle(start, next);
    dp_cc[cur][0] += dp_cc[next][1];
    dp_cc[cur][1] += min(dp_cc[next][0], dp_cc[next][1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++i) {
        scanf("%d", &a[i]);
        rev[a[i]].push_back(i);
    }
    for (int i = 1 ; i <= n ; ++i)
        scanf("%d", &c[i]);

    LL ans = 0;
    for (int i = 1 ; i <= n ; ++i) {
        if (vis[i]) continue;
        //printf("check i: %d\n", i);

        vector<int> cycle;
        find_cycle(i, cycle);
        for (auto t : cycle) {
            in_cycle[t] = true;
            //printf("in_cycle: %d\n", t);
        }
        for (auto t : cycle) {
            tree_dp(t);
        }
        //for (int t = 1 ; t <= n ; ++t)
        //    printf("dp[%d][0]: %d, dp[%d][1]:%d\n", t, dp[t][0], t, dp[t][1]);
        if (cycle.size() > 1) {
            // clear
            for (auto t : cycle) {
                dp_cc[t][0] = dp_cc[t][1] = LLINF;
            }
            try_cycle(cycle[0], cycle[0]);
            LL tmp = dp_cc[cycle[0]][1];
            for (auto t : cycle) {
                dp_cc[t][0] = dp_cc[t][1] = LLINF;
            }
            try_cycle(cycle[1], cycle[1]);
            tmp = min(tmp, dp_cc[cycle[1]][1]);
            ans += tmp;
        } else {
            //ans += min(dp[cycle[0]][0], dp[cycle[0]][1]);
            ans += dp[cycle[0]][1] - c[cycle[0]];
        }
    }
    printf("%lld\n", ans);
    return 0;
}