#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 310;
const int MAXT = 100010;
const int MOD = 1000000007;
vector<int> mp[MAXN];
int dp[MAXN][MAXT];
int a[MAXN], tail[MAXN];
int deg[MAXN];
int e[MAXN][2];

int main() {
  int n, q, T;
  scanf("%d%d%d",&n,&q,&T);
  for (int i = 0 ; i < n ; ++i) {
    scanf("%d",&a[i]);
    tail[i] = a[i];
  }
  for (int i = 0 ; i < q ; ++i) {
    int t1, t2;
    scanf("%d%d",&t2,&t1);
    --t1; --t2;
    mp[t1].push_back(t2);
    e[i][0] = t1; e[i][1] = t2;
    ++deg[t2];
  }
  int vis[MAXN];
  memset(vis, 0, sizeof(vis));
  vector<int> topsort;
  while (1) {
    int flg = 0;
    for (int i = 0 ; i < n ; i++) {
      if (vis[i] || deg[i]) continue;
      if (deg[i] == 0) {
        flg = 1;
        topsort.push_back(i);
        vis[i] = 1;
        for (int j = 0 ; j < mp[i].size(); ++j)
          --deg[mp[i][j]];
      }
    }
    if (!flg) break;
  }
  if (topsort.size() < n) {
    printf("0\n");
    return 0;
  }
  for (int i = n-1 ; i >=0 ; --i) {
    int id = topsort[i];
    for (int j = 0; j < q ; ++j) {
      if (e[j][1] == id) tail[e[j][0]] += tail[id];
    }
  }
  for (int i = 0 ; i < n ;i++) tail[i] -= a[i];
  /*
  for (int i = 0 ; i < n ;i++)
    printf(" %d", topsort[i]+1);
  printf("\n");
  for (int i = 0 ; i < n ;i++)
    printf(" tail[%d]:%d\n", i+1, tail[i]);
  */
  dp[0][0] = 1;
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j <= T ; ++j) {
      if (j >= tail[i]) {
        dp[i+1][j] += dp[i][j-tail[i]];
        dp[i+1][j] %= MOD;
      }
      if (j >= a[i] + tail[i]) {
        dp[i+1][j] += dp[i+1][j-a[i]-tail[i]];
        dp[i+1][j] %= MOD; 
      }
    }
  }
  printf("%d\n", dp[n][T]);
  return 0;
}

