#include <cstdio>
#include <cstring>

char buf[5010];

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%s", buf);
		int n = strlen(buf);
		int c = 0;
		for (int i = 0 ; i < n ; ++i)
			if (buf[i] == 'B') ++c;
		printf("Case #%d: ", ca);
		if (n == 2) {
			printf("N\n");
			continue;
		}
		if (c >= n / 2 && c <= n-2) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}