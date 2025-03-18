#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 2e5+10;
int a[MAXN*2];
int n, m;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i = 0 ; i < n ; ++i) {
            scanf("%d", &a[i]);
            a[i] %= m;
        }
        sort(a, a+n);
        for (int i = n ; i < n+n ; ++i)
            a[i] = a[i-n] + m;

        LL left = 0, right = 0;
        int mid = n / 2, leftp = 0;
        for (int i = 0 ; i < n ; ++i) {
            if (i < mid) left += a[mid] - a[i];
            else right += a[i] - a[mid];
        }

        LL best = left + right;
        //printf("left: %lld, right: %lld\n", left, right);
        for (int i = 1 ; i < n ; ++i) {
            int dis = a[mid+1] - a[mid];
            
            left -= a[mid] - a[leftp];
            left += (LL)dis * (n/2);
            right -= (LL)dis * (n-n/2-1);
            right += a[leftp+n] - a[mid+1];

            if (best > left + right) best = left + right;
            //printf("left: %lld, right: %lld\n", left, right);

            ++mid;
            ++leftp;
        }
        printf("%lld\n", best);
    }
    return 0;
}