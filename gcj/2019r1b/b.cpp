#include <cstdio>

int c[10];

int main() {
	int T, W;
	scanf("%d%d",&T,&W);
	if (W != 6) return 0;
	for (int ca = 1 ; ca <= T ; ++ca) {
		for (int i = 1 ; i <= 6 ; ++i) {
			printf("%d\n", i);
			fflush(stdout);
			scanf("%d", &c[i]);
		}
		int flg = 0;
		for (int w = 0 ; w <= 100 ; ++w) {
			int A = c[1] - w;
			int B = c[2] - w;
			int C = c[3] - w;
			int D = c[4] - w;
			int E = c[5] - w;
			// int F = c[6] - 3 * w;
			if (A < 0 || B < 0 || C < 0 || D < 0 || E < 0) continue;
			if ((E - 2 * B) % 24 != 0) continue;
			int x = (E - 2 * B) / 24;
			if ((-12 * A + 14 * B - E) % 12 != 0) continue;
			int y = (-12 * A + 14 * B - E) / 12;
			if ((-4 * B + 6 * C - E) % 6 != 0) continue;
			int z = (-4 * B + 6 * C - E) / 6;
			if ((12 * A - 10 * B - 6 * C + 6 * D - E) % 6 != 0) continue;
			int u = (12 * A - 10 * B - 6 * C + 6 * D - E) / 6;
			if ((4 * B - 3 * D + E) % 3 != 0) continue;
			int v = (4 * B - 3 * D + E) / 3;

			if (64 * x + 8 * y + 4 * z + 2 * u + 2 * v + 2 * w != c[6])
				continue;

/*
			if ((- A - 2 * B + E) % 46 != 0) continue;
			int x = (- A - 2 * B + E) / 46;
			if ((-21 * A + 27 * B - 2 * E) % 46 != 0) continue;
			int y = (-21 * A + 27 * B - 2 * E) / 46;
			if ((4 * A - 15 * B + 23 * C - 4 * E) % 46 != 0) continue;
			int z = (4 * A - 15 * B + 23 * C - 4 * E) / 46;
			if ((50 * A - 38 * B - 23 * C + 23 * D - 4 * E) % 46 != 0) continue;
			int u = (50 * A - 38 * B - 23 * C + 23 * D - 4 * E) / 46;
			if ((16 * A + 32 * B - 23 * D + 7 * E) % 46 != 0) continue;
			int v = (16 * A + 32 * B - 23 * D + 7 * E) / 46;
			*/
			printf("%d %d %d %d %d %d\n", x, y, z, u, v, w);
			fflush(stdout);
			int ans;
			scanf("%d", &ans);
			flg = 1;
			break;
		}
		if (!flg) {
			printf("didn't find\n");
			return 0;
		}
	}
	return 0;
}