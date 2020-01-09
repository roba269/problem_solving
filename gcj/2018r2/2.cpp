#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 510;
int vis[MAXN][MAXN];

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int a, b;
		scanf("%d%d",&a,&b);

		int ans = 0;
		memset(vis, 0, sizeof(vis));
		while (a > 0 || b > 0) {
			int flg = false;
			for (int t = 1 ; t <= a + b ; ++t) {
				for (int ta = 0 ; ta <= a ; ++ta) {
					int tb = t - ta;
					if (tb < 0 || tb > b || vis[ta][tb]) continue;
					vis[ta][tb] = 1;
					a -= ta; b -= tb;
					++ans;
					// printf("(%d,%d)\n", ta, tb);
					flg = true;
					break;
				}
				if (flg) break;
			}
			if (!flg) break;
		}

		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}