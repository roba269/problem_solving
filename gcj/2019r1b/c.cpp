#include <cstdio>

const int MAXN = 100010;
int c[MAXN], d[MAXN];

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int n, k;
		int ans = 0;
		scanf("%d%d", &n, &k);
		for (int i = 0 ; i < n ; ++i)
			scanf("%d",&c[i]);
		for (int i = 0 ; i < n ; ++i)
			scanf("%d",&d[i]);
		for (int L = 0 ; L < n ; ++L)
			for (int R = L ; R < n ; ++R) {
				int maxc = -1, maxd = -1;
				for (int i = L ; i <= R ; ++i) {
					if (c[i] > maxc) maxc = c[i];
					if (d[i] > maxd) maxd = d[i];
				}
				if (maxc - maxd >= -k && maxc - maxd <= k) {
					++ans;
				}
			}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}