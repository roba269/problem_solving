#include <cstdio>

int main() {
	int T, ca, n, m, k;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d%d%d",&n,&m,&k);
		int t1, t2;
		scanf("%d%d",&t1,&t2);
		int flg = (t1 + t2) % 2;
		bool res = true;
		for (int i = 0 ; i < k ; ++i) {
			scanf("%d%d",&t1,&t2);
			if ((t1+t2) % 2 != flg) {
				res = false;
			}
		}
		printf("Case #%d: ", ca);
		if (k < 2) printf("N\n");
		else if (res) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}