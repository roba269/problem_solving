#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN = 1e5+10;
int a[MAXN];
int ans[MAXN];
bool vis[MAXN];
int tmp[MAXN], output[MAXN];
	
bool check(int *a, int *ans, int n) {
	// check if is permutation
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0 ; i < n ; ++i) {
		if (ans[i] < 1 || ans[i] > n) return false;
		tmp[ans[i]] = 1;
	}
	for (int i = 1 ; i <= n ; ++i)
		if (tmp[i] != 1) return false;

	// check if ans is correct
	int L = 0, R = n-1, p = 0;
	while (L < R) {
		if (ans[L] < ans[R]) {
			output[p++] = ans[--R];
		} else {
			output[p++] = ans[++L];
		}
	}
	for (int i = 0 ; i < n-1 ; ++i)
		if (output[i] != a[i]) return false;
	return true;
}

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int c1 = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0 ; i < n-1 ; ++i) {
			scanf("%d", &a[i]);
			vis[a[i]] = 1;
			if (a[i] == 1) c1++;
		}
		if (c1 == 2) {
			int missing[2], pm = 0;
			for (int i = 1 ; i <= n ; ++i)
				if (!vis[i] && pm < 2) missing[pm++] = i;
			ans[0] = missing[0];
			ans[n-1] = missing[1];
			int L = 0, R = n-1, p = 0;
			while (L < R) {
				if (ans[L] < ans[R]) {
					ans[--R] = a[p++];
				} else {
					ans[++L] = a[p++];
				}
			}
		} else if (c1 == 1) {
			// 1 at the left most
			ans[0] = 1;
			for (int i = 0 ; i < n-2 ; ++i)
				ans[n-2-i] = a[i];
			int missing;
			for (int i = 1 ; i <= n ; ++i) {
				if (!vis[i]) {missing = i; break;}
			}
			ans[n-1] = missing;
		} else {
			printf("-1\n");
			continue;
		}
		//for (int i = 0 ; i < n ; ++i)
		//	printf("[%d]", ans[i]);
		//printf("\n");
		if (check(a, ans, n)) {
			for (int i = 0 ; i < n ; ++i) {
				if (i) printf(" ");
				printf("%d", ans[i]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
	return 0;
}