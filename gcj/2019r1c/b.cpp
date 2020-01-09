#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;

int ans[20];

void output() {
		char final[10];
		for (int i = 0 ; i < 5 ; ++i) {
			final[i] = ans[i] + 'A';
		}
		final[5] = 0;
		printf("%s\n", final);
		fflush(stdout);
		// fprintf(stderr, "MyOutput: %s\n", final);
		char judge[5];
		scanf("%s", judge);
		if (judge[0] != 'Y') exit(0);
		// else fprintf(stderr, "Yes!\n");
}

void solve(int dig, const set<int>& st) {
	// fprintf(stderr, "dig: %d, try set size: %d\n", dig, st.size());
	/*
	if (dig == 4) {
		ans[4] = 1 + 2 + 3 + 4;
		for (int i = 0 ; i < dig ; ++i)
			ans[4] -= ans[i];
		char final[10];
		for (int i = 0 ; i < 5 ; ++i) {
			final[i] = ans[i] + 'A';
		}
		final[5] = 0;
		printf("%s\n", final);
		fflush(stdout);
		fprintf(stderr, "MyOutput: %s\n", final);
		return;
	}
	*/
	char tmpbuf[4];
	int cnt[10];
	set<int> next_st[5];
	memset(cnt, 0, sizeof(cnt));
	for (auto item : st) {
		int idx = item * 5 + dig;
		printf("%d\n", idx+1);
		fflush(stdout);
		scanf("%s", tmpbuf);
		++cnt[tmpbuf[0]-'A'];
		next_st[tmpbuf[0]-'A'].insert(item);
	}
	if (st.size() == 1) {
		int next;
		for (int i = 0 ; i < 5 ; ++i)
			if (cnt[i] > 0) {next = i; break;}
		ans[3] = 1 + 2 + 3 + 4 - ans[0] - ans[1] - ans[2] - next;
		ans[4] = next;
		output();
		return;
	}

	int mc = 0;
	for (int i = 0 ; i < 5 ; ++i)
		if (cnt[i] > mc) mc = cnt[i];
	for (int i = 0 ; i < 5 ; ++i)
		if (cnt[i] > 0 && cnt[i] < mc) {
			ans[dig] = i;
			solve(dig+1, next_st[i]);
			break;
		}
}

int main() {
	int T, F;
	scanf("%d%d",&T,&F);
	for (int ca = 1 ; ca <= T ; ++ca) {
		set<int> st;
		for (int i = 0 ; i < 119 ; ++i)
			st.insert(i);
		memset(ans, 0, sizeof(ans));
		solve(0, st);
	}
	return 0;
}