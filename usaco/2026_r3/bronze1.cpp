#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int T, n, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        map<int,int> cnt;
        int ma = -1e9, mi = 1e9;
        for (int i = 0 ; i < n ; ++i) {
            int tmp;
            scanf("%d", &tmp);
            cnt[tmp]++;
            ma = max(ma, tmp);
            mi = min(mi, tmp);
        }
        long long tot = 0;
        if (k > 0) {
            for (int v = mi ; v <= ma ; ++v) {
                if (cnt.count(v) == 0) continue;
                if (cnt[v] == 1) continue;
                tot += cnt[v] - 1;
                if (v+k <= ma) cnt[v+k] += cnt[v] - 1;
                else tot += (long long)(cnt[v] - 1) * (cnt[v] - 2) / 2;
            }
        } else {
            for (int v = ma ; v >= mi ; --v) {
                if (cnt.count(v) == 0) continue;
                if (cnt[v] == 1) continue;
                tot += cnt[v] - 1;
                if (v+k >= mi) cnt[v+k] += cnt[v] - 1;
                else tot += (long long)(cnt[v] - 1) * (cnt[v] - 2) / 2;
            }
        }
        cout << tot << endl;
    }
    return 0;
}