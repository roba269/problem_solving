#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 310;
const int INF = 10000000;
int a[MAXN][MAXN];
int L[MAXN*MAXN];
int H, S;
int dp[MAXN*2][MAXN*2][2];

typedef pair<int,int> PII;

int mk[MAXN][MAXN];
bool preprocess(int flg, vector<PII>& out) {
	int cnt = 0;
	memset(mk, 0, sizeof(mk));
	out.clear();
	while (cnt < H * S) {
		int tc = 0;
		int col, row;
		for (col = 0 ; col < S ; ++col) {
			for (row = 0 ; row < H ; ++row) {
				if (mk[row][col] == 0) break;
			}
			while (row < H && a[row][col] == flg) {
				mk[row][col] = 1;
				++tc;
				++row;
			}
		}
		if (tc == 0) {
			return false;
		}
		cnt += tc;
		out.push_back(make_pair(tc, flg));
		flg = 1 - flg;
	}
	return true;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int K;
		scanf("%d%d%d",&H,&S,&K);
		for (int i = 0 ; i < H ; ++i) {
			char buf[MAXN];
			scanf("%s", buf);
			for (int j = 0 ; buf[j] ; ++j)
				a[i][j] = (buf[j] == 'B');
		}
		for (int i = 0 ; i < K ; ++i)
			scanf("%d",&L[i]);

		vector<PII> seq;
		if (!preprocess(1, seq)) {
			preprocess(0, seq);
		}
/*
		for (int i = 0 ; i < seq.size() ; ++i)
			printf("(%d,%d) ", seq[i].first, seq[i].second);
*/		

		memset(dp, 0x3f, sizeof(dp));
		int tmp_sum = 0;
		for (int i = 0 ; i < seq.size() ; ++i) {
			dp[i+1][1][seq[i].second] = tmp_sum;
			tmp_sum += seq[i].first;
		}
		for (int i = 1 ; i < seq.size() ; ++i) {
			for (int j = 1 ; j <= i ; ++j) {
				for (int flg = 0; flg < 2 ; ++flg) {
					if (dp[i][j][flg] >= INF) continue;

					if (seq[i].second == flg) {
						dp[i+1][j][flg] = min(dp[i+1][j][flg], dp[i][j][flg]);
					} else {
						dp[i+1][j+1][seq[i].second] = min(dp[i+1][j+1][seq[i].second], dp[i][j][flg]); // do nothing
						dp[i+1][j][flg] = min(dp[i+1][j][flg], dp[i][j][flg] + seq[i].first); // avoid switch
					}
				}
			}
		}
		int len = seq.size();
/*
		for (int i = 0 ; i <= len ; ++i) {
			for (int sw_cnt = 0 ; sw_cnt <= len ; ++sw_cnt) {
				for (int flg = 0 ; flg < 2 ; ++flg)
					printf("dp[%d][%d][%d]:%d\n", i, sw_cnt, flg, dp[i][sw_cnt][flg]);
			}
		}
*/
		printf("Case #%d:", ca);

		for (int i = 0 ; i < K ; ++i) {
			bool ff = false;
			for (int sw_cnt = 0 ; sw_cnt <= len ; ++sw_cnt) {
				if (dp[len][sw_cnt][0] <= L[i] || dp[len][sw_cnt][1] <= L[i]) {
					printf(" %d", sw_cnt);
					ff = true;
					break;
				}
			}
			if (!ff) printf(" %d", len);
		}
		printf("\n");
	}
	return 0;
}