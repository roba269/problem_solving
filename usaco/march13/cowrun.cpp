#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;
const int MAXN = 1010;
const LL INF = 1000000100LL * 1000000100LL;
int a[MAXN];
long long dp[MAXN][MAXN][2];
int zidx;
int n;

LL solve(int L, int R, int flg) {
  if (L == R) {
    if (L == zidx) return 0;
    return INF;
  }
  if (dp[L][R][flg] != -1) return dp[L][R][flg];
  int cnt = L + (n - 1 - R) + 1;
  LL ans = INF;
  if (flg == 0) {
    int tmp = solve(L+1, R, 0) + (LL)(a[L+1] - a[L]) * cnt;
    if (tmp < ans) ans = tmp;
    tmp = solve(L+1, R, 1) + (LL)(a[R] - a[L]) * cnt;
    if (tmp < ans) ans = tmp;
  } else {
    LL tmp = solve(L, R-1, 0) + (LL)(a[R] - a[L]) * cnt;
    if (tmp < ans) ans = tmp;
    tmp = solve(L, R-1, 1) + (LL)(a[R] - a[R-1]) * cnt;
    if (tmp < ans) ans = tmp;
  }
  return dp[L][R][flg] = ans;
}

int main() {
  freopen("cowrun.in","r",stdin);
  freopen("cowrun.out","w",stdout);
  scanf("%d",&n);
  for (int i = 0 ; i < n ; i++)
    scanf("%d",&a[i]);
  a[n++] = 0;
  sort(a, a+n);
  for (int i = 0 ; i < n ; ++i)
    if (a[i] == 0) {zidx = i; break;}
  memset(dp, -1, sizeof(dp));
  LL ans = min(solve(0, n-1, 0), solve(0, n-1, 1));
  cout << ans << endl;
	return 0;
}
