#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 5e5+10;
int a[MAXN];
int st[MAXN], lo[MAXN];
int ans[MAXN];

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0 ; i < n ; ++i)
			scanf("%d", &a[i]);

		int hi = -1;
		int nsec = 0;
		for (int i = 0 ; i < n ; ++i) {
			if (a[i] > hi) {
				hi = a[i];
				st[nsec] = i;
				lo[nsec] = a[i];
				++nsec;
			} else {
				if (a[i] < lo[nsec-1]) {
					lo[nsec-1] = a[i];
				}
			}
		}

		int prev_lo = 1e9, prev_ans = 1e9;
		for (int i = nsec - 1 ; i >= 0 ; --i) {
			if (a[st[i]] > prev_lo) {
				ans[i] = prev_ans;
				prev_lo = min(prev_lo, lo[i]);
			} else {	// can't jump to right section
				prev_ans = a[st[i]];
				ans[i] = prev_ans;
				prev_lo = lo[i];
			}
		}

		for (int i = 0 ; i < nsec ; ++i) {
			int R;
			if (i < nsec - 1) R = st[i+1];
			else R = n;
			for (int j = st[i] ; j < R ; ++j) {
				printf("%d ", ans[i]);
			}
		}
		printf("\n");
	}
	return 0;
}