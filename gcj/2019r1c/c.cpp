#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;

int R, C;
char buf[20][20];
int sg[16][16][16][16];
int ans;

int solve(int x1, int y1, int x2, int y2, int dep) {
	if (sg[x1][y1][x2][y2] != -1)
		return sg[x1][y1][x2][y2];
	set<int> vis;
	for (int x = x1 ; x <= x2 ; ++x) {
		int flg = 1;
		for (int y = y1 ; y <= y2 ; ++y)
			if (buf[x][y] == '#') {flg = 0; break;}
		if (flg == 0) continue;

		int tmp = 0;
		if (x > x1) {
			tmp ^= solve(x1, y1, x-1, y2, dep+1);
		}
		if (x < x2) {
			tmp ^= solve(x+1, y1, x2, y2, dep+1);
		}

		if (dep == 0 && tmp == 0) {
			ans += y2 - y1 + 1;
		}
		vis.insert(tmp);
	}
	for (int y = y1 ; y <= y2 ; ++y) {
		int flg = 1;
		for (int x = x1 ; x <= x2 ; ++x)
			if (buf[x][y] == '#') {flg = 0; break;}
		if (flg == 0) continue;
		int tmp = 0;
		if (y > y1) {
			tmp ^= solve(x1, y1, x2, y-1, dep+1);
		}
		if (y < y2) {
			tmp ^= solve(x1, y+1, x2, y2, dep+1);
		}
		if (dep == 0 && tmp == 0) {
			ans += x2 - x1 + 1;
		}
		vis.insert(tmp);
	}
	/*
	printf("[%d,%d,%d,%d]:", x1, y1, x2, y2);
	for (auto itr = vis.begin() ; itr != vis.end() ; ++itr)
		printf(" %d", *itr);
	printf("\n");
	*/
	for (int v = 0 ; ; ++v)
		if (vis.count(v) == 0) {
			return sg[x1][y1][x2][y2] = v;
		}
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d%d", &R, &C);
		for (int i = 0 ; i < R ; ++i)
			scanf("%s", buf[i]);
		memset(sg, -1, sizeof(sg));
		printf("Case #%d: ", ca);
		ans = 0;
		solve(0, 0, R-1, C-1, 0);
		printf("%d\n", ans);
	}
	return 0;
}