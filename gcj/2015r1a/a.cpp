#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1010];

int main() {
	int T, n;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d",&n);
		for (int i = 0 ; i < n ; ++i)
			scanf("%d",&a[i]);
		int t = 0;
		for (int i = 0 ; i+1 < n ; ++i) {
			if (a[i] >= a[i+1]) t = max(t, a[i]-a[i+1]);
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 0 ; i+1 < n ; ++i) {
			if (a[i] >= a[i+1]) ans1 += a[i] - a[i+1];
			ans2 += min(t, a[i]);
		}
		printf("Case #%d: %d %d\n", ca, ans1, ans2);
	}
	return 0;
}