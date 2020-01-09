#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXA = 300;
const int MAXN = 510;
char buf[MAXA][MAXN];
char ans[MAXN];
int cnt[300], len[MAXA], win[MAXA];

bool can_beat(char a, char b) {
	return (a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R');
}

char beat(char a) {
	if (a == 'R') return 'P';
	if (a == 'P') return 'S';
	return 'R';
}

int main() {
	int T, A;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		memset(buf, 0, sizeof(buf));
		scanf("%d",&A);
		for (int i = 0 ; i < A ; ++i) {
			scanf("%s", buf[i]);
			len[i] = strlen(buf[i]);
		}
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		memset(win, 0, sizeof(win));
		int flg = 0;
		for (int i = 0 ; i < 500 ; ++i) {
			cnt['R'] = cnt['S'] = cnt['P'] = 0;
			vector<char> tot;
			for (int j = 0 ; j < A ; ++j) {
				if (win[j]) continue;
				if (cnt[buf[j][i % len[j]]] == 0) {
					cnt[buf[j][i % len[j]]] = 1;
					tot.push_back(buf[j][i % len[j]]);
				}
			}
			if (tot.size() == 1) {
				ans[i] = beat(tot[0]);
				flg = 1;
				break;
			} else if (tot.size() == 2) {
				if (can_beat(tot[0], tot[1])) {
					ans[i] = tot[0];
				} else ans[i] = tot[1];
				for (int j = 0 ; j < A ; ++j) {
						if (buf[j][i % len[j]] != ans[i])
							win[j] = 1;
				}
			} else {
				break;
			}
		}
		printf("Case #%d: ", ca);
		if (flg == 0) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%s\n", ans);
		}
	}
	return 0;
}