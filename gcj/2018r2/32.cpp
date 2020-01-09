#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 110;
int n;
int a[MAXN][MAXN];

int row[MAXN][MAXN*2];
int col[MAXN][MAXN*2];
int best;
int dup;

void solve(int p, int pos) {
	if (p >= best) return;
	if (dup == 0) {
		if (p < best) best = p;
		return;
	}
	for ( ; pos < n * n ; ++pos) {
		int i, j;
		i = pos / n;
		j = pos % n;
		if (row[i][a[i][j]+n] > 1 || col[j][a[i][j]+n] > 1) {
			int tdup = dup;
			if (row[i][a[i][j]+n] > 1 && --row[i][a[i][j]+n] <= 1) --dup;
			if (col[i][a[i][j]+n] > 1 && --col[j][a[i][j]+n] <= 1) --dup;
			solve(p+1, pos+1);
			dup = tdup;
			++row[i][a[i][j]+n];
			++col[j][a[i][j]+n];
		}
		solve(p, pos+1);
	}
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d",&n);
		for (int i = 0 ; i < n ; ++i)
			for (int j = 0 ; j < n ; ++j)
				scanf("%d",&a[i][j]);

		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < n ; ++j) {
				++row[i][a[i][j]+n];
				++col[j][a[i][j]+n];
			}
		}

		dup = 0;
		for (int i = 0 ; i < n ; ++i)
			for (int j = 0 ; j <= n+n ; ++j) {
				if (row[i][j] > 1) ++dup;
				if (col[i][j] > 1) ++dup;
			}

		best = 10000000;
		solve(0, 0);
		printf("Case #%d: %d\n", ca, best);
	}
	return 0;
}