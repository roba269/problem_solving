#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 2e5 + 10;
int a[MAXN], n;
int del[MAXN];

inline int findL(int v) {
    return lower_bound(a, a+n, v) - a;
}

inline int findR(int v) {
    return upper_bound(a, a+n, v) - a - 1;
}

struct SS {int L, R, t;} seg[MAXN];
int cmp(SS a, SS b) {
    if (a.R != b.R) return a.R < b.R;
    return a.L > b.L;
}

inline int lsb(int x) {return x & -x;}

int prefix_sum(int v) {
    int sum = 0;
    ++v;
    if (v == 0) return 0;
    while (v) {
        sum += del[v];
        v -= lsb(v);
    }
    return sum;
}

inline int range_query(int L, int R) {
    return prefix_sum(R) - prefix_sum(L-1);
}

void mark_del(int v) {
    for (++v; v < MAXN ; v += lsb(v)) {
        del[v]++;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int k;
        scanf("%d%d",&n,&k);
        for (int i = 0 ; i < n ; ++i)
            scanf("%d", &a[i]);
        sort(a, a+n);
        for (int i = 0 ; i < k ; ++i) {
            int tl, tr, tt;
            scanf("%d%d%d", &tl, &tr, &tt);
            seg[i].L = findL(tl);
            seg[i].R = findR(tr);
            seg[i].t = tt;
            //printf("[%d,%d]\n", seg[i].L, seg[i].R);
        }
        sort(seg, seg+k, cmp);
        set<int> pts;
        for (int i = 0 ; i < n ; ++i)
            pts.insert(i);
        memset(del, 0, sizeof(del));
        for (int i = 0 ; i < k ; ++i) {
            int tokeep = seg[i].t - range_query(seg[i].L, seg[i].R);
            if (tokeep <= 0) continue;
            //printf("tokeep: %d\n", tokeep);
            auto itr = pts.upper_bound(seg[i].R);
            --itr;
            while (tokeep--) {
                auto prev = itr;
                //printf("del %d\n", *itr);
                --prev;
                mark_del(*itr);
                pts.erase(itr);
                itr = prev;
            }
        }
        printf("%d\n", pts.size());
    }
    return 0;
}