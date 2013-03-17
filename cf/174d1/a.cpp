#include <cstdio>

const int MAXN = 200010;
typedef long long LL;
LL a[MAXN];
LL d[MAXN];

int main() {
  int cnt = 1, T;
  LL tot = 0;
  scanf("%d",&T);
  while (T--) {
    int cmd, i, delta;
    scanf("%d",&cmd);
    if (cmd == 1) {
      scanf("%d%d",&i,&delta);
      d[i-1] += delta;
      tot += (LL)i * delta;
    } else if (cmd == 2) {
      scanf("%d",&i);
      a[cnt++] = i;
      tot += i;
    } else {
      d[cnt-2] += d[cnt-1];
      tot -= a[cnt-1] + d[cnt-1];
      d[cnt-1] = 0;
      --cnt;
    }
    printf("%.9lf\n", (double)tot / cnt);
  }
  return 0;
}

