#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
const int MAXN = 55;

struct SEG {
	int x, y1, y2;
} seg[MAXN];

const int INF = 1000000001;

int flow[MAXN][MAXN],cap[MAXN][MAXN];
int q[MAXN],res[MAXN][MAXN],fa[MAXN];

int maxflow(int cap[][MAXN],int n,int src,int dst,int flow[][MAXN])
{
	int ans, head, tail, i, del, p;
	memcpy(res,cap,sizeof(res));
	ans = 0;
	while (1) {
		memset(fa,-1,sizeof(fa));
		q[0] = src; head = 0; tail = 1;
		while (head < tail) {
			if (q[head] == dst) break;
			for (i = 0 ; i < n ; i++)
				if (res[q[head]][i] && fa[i] == -1) {
					q[tail++] = i;
					fa[i] = q[head];
				}	
			++head;
		}
		if (head == tail) break;
		del = INF;
		for (p = dst ; p != src ; p = fa[p])
			if (res[fa[p]][p] < del) del = res[fa[p]][p];	
		for (p = dst ; p != src ; p = fa[p]) {
			flow[fa[p]][p] += del;
			flow[p][fa[p]] -= del;
			res[fa[p]][p] -= del;
			res[p][fa[p]] += del;
		}
		ans += del;
	}
	return ans;
}

PII get_overlap(int s1, int e1, int s2, int e2) {
	int s = max(s1, s2);
	int e = min(e1, e2);
	if (s <= e) return make_pair(s, e);
	return make_pair(0, 0);
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		memset(flow,0,sizeof(flow));
		memset(cap, 0, sizeof(cap));
		int n, H;
		scanf("%d%d",&n,&H);
		bool flg = true;
		int S = n, T = n+1;
		for (int i = 0 ; i < n ; ++i) {
			scanf("%d%d%d", &seg[i].x, &seg[i].y1, &seg[i].y2);
			if (seg[i].y1 == 0 && seg[i].y2 == H) {
				flg = false;
			} else if (seg[i].y1 == 0) {
				cap[S][i] = INF;
			} else if (seg[i].y2 == H) {
				cap[i][T] = INF;
			}
		}
		printf("Case #%d: ", ca);
		if (!flg) {
			printf("-1\n");
			continue;
		}

		for (int i = 0 ; i < n ; ++i)
			for (int j = i+1 ; j < n ; ++j) {
				int minx = min(seg[i].x, seg[j].x);
				int maxx = max(seg[i].x, seg[j].x);
				pair<int,int> lp = get_overlap(seg[i].y1, seg[i].y2, seg[j].y1, seg[j].y2);
				if (lp.first == lp.second) {
					continue;
				}
				vector<PII> ends;
				for (int k = 0 ; k < n ; ++k) {
					if (seg[k].x <= minx || seg[k].x >= maxx)
						continue;
					pair<int,int> tmp_lp = get_overlap(lp.first, lp.second, seg[k].y1, seg[k].y2);
					if (tmp_lp.first < tmp_lp.second) {
						ends.push_back(make_pair(tmp_lp.first, 0));
						ends.push_back(make_pair(tmp_lp.second, 1));
					}
				}
				sort(ends.begin(), ends.end());
				int cover = 0, len = 0;
				for (int k = 0 ; k < ends.size() ; ++k) {
					if (cover > 0 && k > 0) {
						len += ends[k].first - ends[k-1].first;
					}
					if (ends[k].second == 0) {
						++cover;
					} else --cover;
					assert(cover >= 0);
				}
				len = lp.second - lp.first - len;
				assert(len >= 0);
				if (len > 0) {
					cap[i][j] = cap[j][i] = len;
				}
			}

		printf("%d\n", maxflow(cap, n+2, S, T, flow));
	}
	return 0;
}