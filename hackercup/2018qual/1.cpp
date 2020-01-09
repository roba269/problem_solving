#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN = 60;
char name[MAXN][32];
bool mk[MAXN];

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int N, K;
		long long V;
		scanf("%d%d%lld",&N,&K,&V);
		for (int i = 0 ; i < N ; ++i)
			scanf("%s", name[i]);
		memset(mk, 0, sizeof(mk));
		int start = (int)((V-1) * (long long)K % N);
		for (int j = 0 ; j < K ; ++j)
			mk[(start+j)%N] = 1;
		printf("Case #%d:", ca);
		for (int i = 0 ; i < N ; ++i)
			if (mk[i]) printf(" %s", name[i]);
		printf("\n");
	}
	return 0;
}

