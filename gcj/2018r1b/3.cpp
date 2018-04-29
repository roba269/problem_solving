#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 110;
int s[MAXN][2];
long long cnt[MAXN];
long long oc[MAXN];
int vis[MAXN];

bool check(long long need, int id) {
	if (!vis[id]) {
		vis[id] = 1;
	} else {
		return false;
	}
	if (need <= oc[id]) {
		oc[id] -= need;
		vis[id] = 0;
		return true;
	}
	long long debt = need - oc[id];
	oc[id] = 0;
	bool b = check(debt, s[id][0]) && check(debt, s[id][1]);
	vis[id] = 0;
	return b;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int n;
		scanf("%d",&n);
		for (int i = 1 ; i <= n ; ++i)
			scanf("%d%d",&s[i][0], &s[i][1]);

		long long ma = 0;
		for (int i = 1 ; i <= n ; ++i) {
			scanf("%lld",&cnt[i]);
			ma += cnt[i];
		}

		long long ans = 0;
		long long lo = 1, hi = ma;
		while (lo <= hi) {
			long long mid = (lo + hi) / 2;
			memcpy(oc, cnt, sizeof(cnt));
			memset(vis, 0, sizeof(vis));
			// printf("=== check for %d\n", mid);
			if (check(mid, 1)) {
				ans = mid;
				lo = mid + 1;
			} else hi = mid - 1;
		}
		printf("Case #%d: %lld\n", ca, ans);
	}
	return 0;
}