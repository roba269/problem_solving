#include <cstdio>

char buf[50010];

int main() {
	int N;
	scanf("%d",&N);
	for (int ca = 1 ; ca <= N ; ++ca) {
		int len;
		scanf("%d%s", &len, buf);
		printf("Case #%d: ", ca);
		for (int i = 0 ; buf[i] ; ++i) {
			if (buf[i] == 'E') printf("S");
			else printf("E");
		}
		printf("\n");
	}
	return 0;
}