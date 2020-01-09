#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

const int MAXN = 310;
int a[MAXN], b[MAXN];

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		set<pair<int,int> > s;
		int n;
		scanf("%d",&n);
		for (int i = 0 ; i < n ; i++) {
			scanf("%d%d",&a[i],&b[i]);
		}
		for (int i = 0 ; i < n ; ++i) {
			for (int j = i+1 ; j < n ; ++j) {
				if ((a[i] == a[j] || b[i] == b[j])) continue;
				int t1 = b[i] - b[j];
				int t2 = a[j] - a[i];
				if ((t1 < 0 && t2 > 0) || (t1 > 0 && t2 < 0))
					continue;
				int g = gcd(t1, t2);
				s.insert(make_pair(t1/g, t2/g));
			}
		}
		printf("Case #%d: %d\n", ca, s.size()+1);
	}
	return 0;
}