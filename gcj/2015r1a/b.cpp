#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int t[1010];

int main() {
	int T, B, N;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d%d", &B, &N);
		int maxt = 0;
		for (int i = 0 ; i < B ; ++i) {
			scanf("%d", &t[i]);
			maxt = max(maxt, t[i]);
		}
		int ans = -1;
		long long lo = 0, hi = (long long)maxt * N;
		while (lo <= hi) {
			long long mid = (lo + hi) / 2;
			long long cnt = 0;
			vector<int> ava;
			for (int i = 0 ; i < B ; ++i) {
				cnt += (mid + t[i] - 1) / t[i];
				if (mid % t[i] == 0) ava.push_back(i+1);
			}
			// printf("mid:%lld cnt:%lld flg:%d\n", mid, cnt, flg);
			if (cnt < N && cnt + ava.size() >= N) {
				ans = ava[N-cnt-1];
				break;
			}
			if (cnt + ava.size() < N) {
				lo = mid + 1;
			} else hi = mid - 1;
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}