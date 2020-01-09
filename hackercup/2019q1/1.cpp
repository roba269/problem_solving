#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int MAXN = 55;
const int MAXM = 2010;
const int INF = 1e9;
int mp[MAXN][MAXN];

struct E {int u, v, w;} e[MAXM];

int main() {
	int T, n, m;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d%d",&n,&m);
		memset(mp, 0x7f, sizeof(mp));
		int i, j, k;
		for (int i = 0 ; i < m ; ++i) {
			int t1, t2, t3;
			scanf("%d%d%d", &t1, &t2, &t3);
			--t1; --t2;
			mp[t1][t2] = mp[t2][t1] = t3;
			e[i].u = t1;
			e[i].v = t2;
			e[i].w = t3;
		}
		for (int k = 0 ; k < n ; ++k) {
			for (int i = 0 ; i < n ; ++i)
				for (int j = 0 ; j < n ; ++j) {
					if (mp[i][k] > INF || mp[k][j] > INF) continue;
					mp[i][j] = std::min(mp[i][j], mp[i][k] + mp[k][j]);
				}
		}
		bool flg = true;
		for (int i = 0 ; i < m ; ++i)
			if (e[i].w > mp[e[i].u][e[i].v]) {
				flg = false; break;
			}
		printf("Case #%d: ", ca);
		if (!flg) {printf("Impossible\n"); continue;}
		printf("%d\n", m);
		for (int i = 0 ; i < m ; ++i)
			printf("%d %d %d\n", e[i].u+1, e[i].v+1, e[i].w);
	}
	return 0;
}