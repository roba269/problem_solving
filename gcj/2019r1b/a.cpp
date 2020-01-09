#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXQ = 100010;
int c1[MAXQ], c2[MAXQ];

int main() {
	int T, n, q;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d%d",&n,&q);
		memset(c1, 0, sizeof(c1));
		memset(c2, 0 ,sizeof(c2));
		for (int i = 0 ; i < n ; ++i) {
			char buf[4];
			int x, y;
			scanf("%d%d%s", &x, &y, buf);
			if (buf[0] == 'N') {
				for (int tmp = y + 1 ; tmp <= q ; ++tmp)
					++c1[tmp];
			} else if (buf[0] == 'S') {
				for (int tmp = 0 ; tmp < y ; ++tmp)
					++c1[tmp];
			} else if (buf[0] == 'E') {
				for (int tmp = x + 1 ; tmp <= q ; ++tmp)
					++c2[tmp];
			} else {
				for (int tmp = 0 ; tmp < x ; ++tmp)
					++c2[tmp];
			}
		}

		int maxc1 = -1, maxc2 = -1;
		int maxi, maxj;
		for (int i = 0 ; i <= q ; ++i)
			if (c1[i] > maxc1) {maxc1 = c1[i]; maxi = i;}
		for (int j = 0 ; j <= q ; ++j)
			if (c2[j] > maxc2) {maxc2 = c2[j]; maxj = j;}
		printf("Case #%d: %d %d\n", ca, maxj, maxi);
	}
	return 0;
}