#include <cstdio>

const int MAXN = 20;
const int INF = 1000000;
int a[MAXN], b[MAXN];

int main() {
	int T, n;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d",&n);
		for (int i = 0 ; i < n ; ++i) {
			scanf("%d%d",&a[i],&b[i]);
		}
		int best1 = INF, best2 = INF;
		for (int x1 = 1 ; x1 <= 200 ; ++x1)
			for (int x2 = 1 ; x2 <= 200 ; ++x2) {
				int prev = 0, flg = 1;
				for (int i = 0 ; i < n ; ++i) {
					int cur = x1 * a[i] + x2 * b[i];
					if (cur > prev) prev = cur;
					else {flg = 0; break;}
				}
				if (flg) {
					if (x1 < best1 || (x1 == best1 && x2 < best2)) {
						best1 = x1; best2 = x2;
					}
				}
			}
		printf("Case #%d: ", ca);
		if (best1 >= INF) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d %d\n", best1, best2);
		}
	}
	return 0;
}