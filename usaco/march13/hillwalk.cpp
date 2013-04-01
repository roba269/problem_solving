#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 100100;
const double eps = 1e-8;
int n;
struct Seg {int x1, y1, x2, y2, idx;} seg[MAXN];
struct Event {int flg, idx, x;} event[MAXN*2];
int cx;

struct seg_cmp {
  bool operator()(const Seg &a, const Seg &b) {
    double ay = (double)(cx - a.x1) * (a.y2 - a.y1) / (a.x2 - a.x1) + a.y1;
    double by = (double)(cx - b.x1) * (b.y2 - b.y1) / (b.x2 - b.x1) + b.y1;
    return ay - by > eps;
  }
};
set<Seg, seg_cmp> st;
set<Seg, seg_cmp>::iterator itr;

int cmp_event(const Event &a, const Event &b) {
  if (a.x != b.x) return a.x < b.x;
  return a.flg > b.flg;
}

int main() {
  freopen("hillwalk.in","r",stdin);
  freopen("hillwalk.out","w",stdout);
  scanf("%d",&n);
  int cidx, e_idx, pe = 0;
  for (int i = 0 ; i < n ; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    seg[i].x1 = x1; seg[i].x2 = x2;
    seg[i].y1 = y1; seg[i].y2 = y2;
    seg[i].idx = i;
    event[pe].flg = 1;
    event[pe].idx = i;
    event[pe].x = x1;
    ++pe;
    event[pe].flg = -1;
    event[pe].idx = i;
    event[pe].x = x2;
    ++pe;
    if (x1 == 0 && y1 == 0) cidx = i;
  }
  sort(event, event+pe, cmp_event);
  int ans = 1;
  for (e_idx = 0 ; e_idx < pe ; ++e_idx) {
    cx = event[e_idx].x;
    //  printf("----\n");
    //  for (itr = st.begin() ; itr != st.end() ; ++itr)
    //    printf("cx:%d [%d %d %d %d]\n", cx, itr->x1, itr->y1, itr->x2, itr->y2);
    if (event[e_idx].flg == 1) {
      // printf("insert idx:%d\n", event[e_idx].idx);
      st.insert(seg[event[e_idx].idx]);
    } else {
      // printf("cidx:%d e_idx:%d event[e_idx].idx:%d\n", cidx, e_idx, event[e_idx].idx);
      st.erase(seg[event[e_idx].idx]);
      if (event[e_idx].idx == cidx) {
        // fall
        // printf("fall st.size:%d\n",st.size());
        itr = st.lower_bound(seg[event[e_idx].idx]);
        if (itr == st.end()) break;
        cidx = itr->idx;
        ++ans;
      }
    } 
  }
  printf("%d\n",ans);
  return 0;
}
