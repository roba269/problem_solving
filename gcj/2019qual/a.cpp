#include <cstdio>
#include <cstring>
#include <cstdlib>

char buf[1010];
char ans[1010];

int main() {
	int N;
	scanf("%d",&N);
	for (int ca = 1 ; ca <= N ; ++ca) {
		scanf("%s", buf);
		memset(ans, 0, sizeof(ans));
		for (int i = 0 ; buf[i] ; ++i) {
			if (buf[i] == '4') {
				buf[i] = '3';
				ans[i] = '1';
			} else {
				ans[i] = '0';
			}
		}
		int idx;
		for (idx = 0 ; ans[idx] == '0' ; ++idx);
		printf("Case #%d: ", ca);
		printf("%s %s\n", buf, ans+idx);
	}
	return 0;
}