#include <cstdio>
#include <algorithm>
using namespace std;

int a[200010];

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0 ; i < n ; ++i)
			scanf("%d", &a[i]);
		for (int i = 0 ; i < n-1 ; ++i)
			if (a[i] == a[i+1] + 1) swap(a[i], a[i+1]);
		bool flg = true;
		for (int i = 0 ; i < n ; ++i)
			if (a[i] != i+1) {flg = false; break;}
		if (flg) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}