#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unordered_set>
using namespace std;

const int MAXN = 500010;
unordered_set<int> mp[MAXN];
int dis[MAXN];
int vis[MAXN], q[MAXN];

int main() {
  int T, n, m, S;
  scanf("%d",&T);
  while (T--) {
    scanf("%d%d",&n,&m);
    unordered_set<int> ava;
    for (int i = 0 ; i < n ; ++i) {
      mp[i].clear();
      ava.insert(i);
    }
    for (int i = 0 ; i < m ; ++i) {
      int t1, t2;
      scanf("%d%d", &t1, &t2);
      --t1; --t2;
      mp[t1].insert(t2);
      mp[t2].insert(t1);
    }
    scanf("%d", &S);
    --S;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q[0] = S; dis[S] = 0; vis[S] = 1; ava.erase(S);
    int qh =0, qt = 1;
    for ( ; qh < qt ; ++qh) {
      if (ava.empty()) break;
      for (auto itr = ava.begin() ; itr != ava.end() ; ) {
        int id = *itr;
        if (mp[q[qh]].find(id) != mp[q[qh]].end()) {++itr; continue;}
        itr = ava.erase(itr);
        dis[id] = dis[q[qh]] + 1;
        q[qt++] = id;
      }
    }
    int first = 1;
    for (int i = 0 ; i < n ; ++i) {
      if (i == S) continue;
      if (!first) printf(" "); else first = 0;
      printf("%d", dis[i]);
    }
    printf("\n");
  }
  return 0;
}

