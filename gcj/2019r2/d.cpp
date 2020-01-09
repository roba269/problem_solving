#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

const int MAXN = 12;
const int MAXS = 100;
const long long INF = 1000000000000LL;
const int MOD = 1000000007;
long long ng[MAXN], g[MAXN];
int a[MAXN], b[MAXN];

int main() {
	int T, n;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d",&n);
		for (int i = 0 ; i < n ; ++i) {
			scanf("%d%d",&a[i],&b[i]);
			--a[i]; --b[i];
		}
		for (int i = 0 ; i < n ; ++i) {
			scanf("%d", &g[i]);
		}

		int stuck;
		int maxg = g[0];
		while (1) {
			memset(ng, 0, sizeof(ng));
			for (int i = 0 ; i < n ; ++i) {
				ng[a[i]] += g[i];
				ng[b[i]] += g[i];
			}
			memcpy(g, ng, sizeof(ng));
			if (g[0] > maxg) {maxg = g[0]; stuck = 0;}
			else {
				if (++stuck > MAXS) break;
			}
			if (maxg > INF) break;
		}
		printf("Case #%d: ", ca);
		if (maxg > INF) {
			printf("UNBOUNDED\n");
		} else {
			printf("%d\n", maxg);
		}
	}
	return 0;
}