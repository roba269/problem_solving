/* AC - Greedy 
Build a graph so that each unique d_i is a node, and if the sum of two node d_i, d_j is A or B, add an edge connect them. (Ignore self-loop for now)
The resulting graph must be a forest of chains (no cycle). Then for each chain, we greedily construct pairs from either one end.
Finally, pairing the remaining cows that can be self-paired, i.e. d_i * 2 == A, or d_i * 2 == B. 
 */

#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long LL;
map<int,int> cnt;
unordered_map<int, unordered_set<int>> g;
unordered_set<int> vis;
int a, b;
LL ans;

void build_graph() {
    for (auto item: cnt) {
        int v = item.first;
        int dst = a - v;
        if (dst >= 0 && dst != v && cnt.count(dst)) {
            g[v].insert(dst);
            g[dst].insert(v);
        }
        dst = b - v;
        if (dst >= 0 && dst != v && cnt.count(dst)) {
            g[v].insert(dst);
            g[dst].insert(v);
        }
    }
}

void find_chain(int cur, int fa, vector<int>& ch) {
    while (1) {
        ch.push_back(cur);
        vis.insert(cur);
        int next = a - cur;
        if (next >= 0 && cnt.count(next) && next != cur && (fa == -1 || next != fa)) {
            int tmp = min(cnt[cur], cnt[next]);
            ans += tmp;
            cnt[cur] -= tmp;
            cnt[next] -= tmp;
            fa = cur; cur = next;
            continue;
        } else {
            next = b - cur;
            if (next >= 0 && cnt.count(next) && next != cur && (fa == -1 || next != fa)) {
                int tmp = min(cnt[cur], cnt[next]);
                ans += tmp;
                cnt[cur] -= tmp;
                cnt[next] -= tmp;
                fa = cur; cur = next;
                continue;
            }
        }
        break;
    }
}

int main() {
    int n;
    ans = 0;
    cin >> n >> a >> b;
    for (int i = 0 ; i < n ; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        cnt[t2] = t1;
    }
    build_graph();

    for (auto item: g) {
        if (item.second.size() > 1) continue;
        if (vis.count(item.first)) continue;
        vector<int> chain;
        find_chain(item.first, -1, chain);
    }
    for (auto c: cnt) {
        if (c.first * 2 == a || c.first * 2 == b) {
            ans += c.second / 2;
        }
    }
    cout << ans << endl;
    return 0;
}