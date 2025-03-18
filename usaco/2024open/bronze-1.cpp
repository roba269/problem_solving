#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 10;
char buf[MAXN][10];
bool ans[MAXN];

vector<vector<bool> > expr, lin, rin;
bool val[MAXN], lft[MAXN], rgt[MAXN];
int idx[MAXN];

inline bool get_boolean(char *buf) {
	return strcmp(buf, "true") == 0;
}

void output() {
	printf("expr.size(): %d\n", expr.size());
	for (int i = 0 ; i < expr.size() ; ++i)
		printf("idx[%d]:%d\n", i, idx[i]);
	for (int i = 0 ; i < expr.size() ; ++i)
		printf("val[%d]:%d\n", i, val[i]);
}

bool replace(int st, int ed, bool v) {
	int st_idx = (upper_bound(idx, idx+expr.size(), st / 2) - idx) - 1;
	int ed_idx = (upper_bound(idx, idx+expr.size(), ed / 2) - idx) - 1;
	bool res = false;
	if (st_idx > 0) res |= lft[st_idx-1];
	if (ed_idx < expr.size()-1) res |= rgt[ed_idx+1];

	int lft_in = st / 2 - idx[st_idx];
	if (lft_in > 0) v &= lin[st_idx][lft_in-1];

	int rgt_in = ed / 2 - idx[ed_idx];
	if (rgt_in+1 < expr[ed_idx].size()) v &= rin[ed_idx][rgt_in+1];

	//printf("st_idx: %d, ed_idx: %d, lft_in: %d, rgt_in: %d\n", st_idx, ed_idx, lft_in, rgt_in);
	return res | v;
}

int main() {
	int n, q;
	vector<bool> empty;
	expr.push_back(empty);
	scanf("%d%d",&n,&q);
	for (int i = 0 ; i < n ; i++) {
		scanf("%s", buf[i]);
	}
	for (int i = 0 ; i < n ; i += 2) {
		if (i == 0 || strcmp(buf[i-1], "and") == 0) {
			expr[expr.size()-1].push_back(get_boolean(buf[i]));
		} else {	// "or"
			vector<bool> tmp;
			tmp.push_back(get_boolean(buf[i]));
			expr.push_back(tmp);
		}
	}

	for (int i = 0 ; i < expr.size() ; ++i) {
		val[i] = true;
		for (auto e : expr[i]) {
			if (!e) {
				val[i] = false;
				break;
			}
		}
	}

	lft[0] = val[0];
	for (int i = 1 ; i < expr.size() ; ++i) {
		lft[i] = (lft[i-1] || val[i]);
	}
	rgt[expr.size()-1] = val[expr.size()-1];
	for (int i = expr.size() - 2 ; i >= 0 ; --i) {
		rgt[i] = (rgt[i+1] || val[i]);
	}

	for (int i = 0 ; i < expr.size() ; ++i) {
		bool cur = true;
		vector<bool> values(expr[i].size(), true);
		for (int j = 0 ; j < expr[i].size() ; ++j) {
			cur &= expr[i][j];
			values[j] = cur;
		}
		lin.push_back(values);

		cur = true;
		for (int j = expr[i].size() - 1 ; j >= 0 ; --j) {
			cur &= expr[i][j];
			values[j] = cur;
		}
		rin.push_back(values);
	}

	idx[0] = 0;
	for (int i = 1 ; i < expr.size() ; ++i) {
		idx[i] = idx[i-1] + expr[i-1].size();
	}

	//output();
	for (int i = 0 ; i < q ; ++i) {
		int st, ed;
		char tmp[20];
		scanf("%d%d%s", &st, &ed, tmp);
		bool target = get_boolean(tmp);

		if (replace(st, ed, target) == target) {
			ans[i] = true;
		} else ans[i] = false;
	}
	for (int i = 0 ; i < q ; ++i) {
		if (ans[i]) printf("Y"); else printf("N");
	}
	printf("\n");
	
	return 0;
}