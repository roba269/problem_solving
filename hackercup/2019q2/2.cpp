#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 4010;
const int INF = 1e9;
bool mp[MAXN][MAXN];
int vis[MAXN];
vector<int> c[MAXN];
int nc;
int n;

int q[MAXN];
bool dp[MAXN][MAXN];
int from[MAXN][MAXN];

int ans[MAXN];

int main() {
	int T, ca;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int m;
		scanf("%d%d",&n,&m);
		memset(mp, 0, sizeof(mp));
		memset(vis, 0, sizeof(vis));
		memset(dp, 0, sizeof(dp));
		nc = 0;
		for (int i = 0 ; i <= n ; ++i)
			c[i].clear();

		for (int i = 0 ; i < m ; ++i) {
			int t1, t2;
			scanf("%d%d",&t1,&t2);
			while (t1 < t2) {
				mp[t1][t2] = mp[t2][t1] = true;
				++t1; --t2;
			}
		}

		for (int i = 1 ; i <= n ; ++i) {
			if (!vis[i]) {
				q[0] = i;
				vis[i] = 1;
				int qh = 0, qt = 1;
				while (qh < qt) {
					for (int j = 1 ; j <= n ; ++j) {
						if (vis[j]) continue;
						if (mp[q[qh]][j]) {
							vis[j] = 1;
							q[qt++] = j;
						}
					}
					++qh;
				}
				for (int tmp = 0 ; tmp < qh ; ++tmp) {
					c[nc].push_back(q[tmp]);
				}
				++nc;
			}
		}

		//printf("nc: %d\n", nc);

		dp[0][0] = 1;
		for (int i = 0 ; i < nc ; ++i) {
			for (int j = 0 ; j <= n ; ++j) {
				if (!dp[i][j]) continue;
				dp[i+1][j] = 1;
				from[i+1][j] = j;
				dp[i+1][j+c[i].size()] = 1;
				from[i+1][j+c[i].size()] = j;
			}
		}

		int best = INF, besti = -1;
		for (int i = 0 ; i <= n ; ++i) {
			if (dp[nc][i]) {
				int diff = abs(n-i-i);
				if (diff < best) {
					best = diff;
					besti = i;
				}
			}
		}
		printf("Case #%d: ", ca);

		memset(ans, 0, sizeof(ans));
		for (int i = nc ; i > 0 ; --i) {
			if (from[i][besti] != besti) {
				for (int tmp = 0 ; tmp < c[i-1].size() ; ++tmp)
					ans[c[i-1][tmp]] = 1;
				besti = from[i][besti];
			}
		}

		for (int i = 1 ; i <= n ; ++i)
			printf("%d", ans[i]);
		printf("\n");
		// printf(" best:%d\n", best);
	}
	return 0;
}