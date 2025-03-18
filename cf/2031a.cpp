#include <cstdio>
#include <unordered_map>
using namespace std;

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		unordered_map<int, int> count;
		int best = 0;
		for (int i = 0 ; i < n ; ++i) {
			int tmp;
			scanf("%d", &tmp);
			int c = ++count[tmp];
			if (c > best) best = c;
		}
		printf("%d\n", n-best);
	}
	return 0;
}

