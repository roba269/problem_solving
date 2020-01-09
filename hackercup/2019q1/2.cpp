#include <cstdio>

const int MAXN = 1000100;
const int MOD = 1000000007;
char buf[MAXN];
int w[MAXN];

int main() {
	int T, n, k;
	w[0] = 2;
	for (int i = 1 ; i < MAXN ; ++i)
		w[i] = (w[i-1] + w[i-1]) % MOD;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d%d",&n,&k);
		scanf("%s", buf);
		int c1 = 0, c2 = 0;
		int ans = 0;
		for (int i = n - 1 ; i >= 0 ; --i) {
			if (buf[i] == 'A') ++c1;
			else ++c2;
			if (c2 - c1 > k) {
				--c2; ++c1;
				ans = (ans + w[i]) % MOD;
			}
			if (c1 >= c2) {c1 = c2 = 0;}
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}