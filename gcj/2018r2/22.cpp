#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 510;
int vis[MAXN][MAXN];
int a, b;
int best;

void solve(int a, int b, int p, int cnt) {
	// printf("(a=%d,b=%d,p=%d)\n", a, b, p);
	if (cnt > best) best = cnt;
	if (a < p) return;
	int tmp = 0;
	for (int i = 0 ; ; ++i) {
		if (a - p >= 0 && b - i >= 0) {
			a -= p;
			b -= i;
			++tmp;
			solve(a, b, p+1, cnt+tmp);
		} else break;
	}
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d%d",&a,&b);

		best = 0;
		solve(a, b, 0, 0);
		printf("Case #%d: %d\n", ca, best-1);
	}
	return 0;
}