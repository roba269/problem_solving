#include <cstdio>

int a[64];

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int n;
		scanf("%d",&n);
		for (int i = 0 ; i < n + 1 ; ++i)
			scanf("%d",&a[i]);
		printf("Case #%d: ", ca);
		if (n % 2 == 0) {
			printf("0\n");
		} else {
			printf("1\n0.0\n");
		}
	}
	return 0;
}