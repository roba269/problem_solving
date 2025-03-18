
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 
// x                 x                                      o   Y  Y  x  o

#include <cstdio>

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n % 2 == 0) {
			for (int i = 0 ; i * 2 < n ; i++) {
				printf("%d %d ", i+1, i+1);
			}
			printf("\n");
			continue;
		}
		if (n < 26) {
			printf("-1\n");
			continue;
		}
		int cnt = 0, tmp = 3;
		for (int i = 1 ; i <= n ; ++i) {
			if (i == 1 || i == 10 || i == 26) {
				printf("1 ");
			} else if (i == 23 || i == 27) {
				printf("2 ");
			} else {
				printf("%d ", tmp);
				++cnt;
				if (cnt % 2 == 0) ++tmp;
			}
		}
		printf("\n");
	}
	return 0;
}