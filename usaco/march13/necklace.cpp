#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 10010;
const int MAXM = 1010;
const int INF = 1000100100;
char s1[MAXN], s2[MAXN];
int dp[2][MAXN];

int pre[MAXN], trans[MAXN][26];
void precompute(char *pat) {
  int p,k;
  pre[0] = k = -1;
  for (p = 1 ; pat[p] ; p++) {
    while (k != -1 && pat[p] != pat[k+1]) k = pre[k];
    if (pat[k+1] == pat[p]) ++k;
    pre[p] = k;
  }
}

int main() {
  freopen("necklace.in","r",stdin);
  freopen("necklace.out","w",stdout);
  scanf("%s%s",s1,s2);
  int status = strlen(s2) + 1;
  int len = strlen(s1);
  precompute(s2);
  for (int st = 0 ; st < status ; ++st) {
    for (char ch = 'a' ; ch <= 'z' ; ++ch) {
      int tmp = st - 1;
      while (tmp != -1 && s2[tmp+1] != ch)
        tmp = pre[tmp];
      if (s2[tmp+1] == ch) ++tmp;
      trans[st][ch-'a'] = tmp+1;
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  int from = 0, to = 1;
  for (int i = 0 ; s1[i] ; ++i) {
    for (int j = 0 ; j < status ; ++j) {
      if (dp[from][j] >= INF) continue;
      // remove
      if (dp[to][j] > dp[from][j] + 1) {
        dp[to][j] = dp[from][j] + 1;
      }
      // follow
      int tmp = trans[j][s1[i]-'a'];
      if (tmp == status - 1) continue;
      if (dp[to][tmp] > dp[from][j]) {
        dp[to][tmp] = dp[from][j];
      }
    } 
    from = 1 - from;
    to = 1 - to;
    memset(&dp[to][0], 0x3f, sizeof(dp[0]));
  }
  /*
  for (int i = 0 ; i <= len ; ++i)
    for (int j = 0 ; j < status ; ++j)
      printf("dp[%d][%d]:%d\n",i,j,dp[i][j]);
  */
  int ans = INF;
  for (int j = 0 ; j < status ; ++j)
    if (dp[from][j] < ans) ans = dp[from][j];
  printf("%d\n", ans);
  return 0;
}

