#include <cstdio>

const int intervals[][2] = {
    {45, 49},
    {445, 499}, 
    {4445, 4999},
    {44445, 49999},
    {444445, 499999},
    {4444445, 4999999},
    {44444445, 49999999},
    {444444445, 499999999},
};

int main() {
    int T, n, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ans = 0;
        for (int i = 0 ; i < 8 ; ++i) {
            if (intervals[i][1] <= n) ans += intervals[i][1] - intervals[i][0] + 1;
            else if (n >= intervals[i][0]) ans += n - intervals[i][0] + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}