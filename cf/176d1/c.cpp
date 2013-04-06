#include <cstdio>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 1000100;
map<int,vector<int> > mp;
map<int,vector<int> >::iterator itr;
int neg[MAXN];
int ans[MAXN], a[MAXN];
int n;

int check(int *ans) {
  vector<int> stk;
  for (int i =0 ; i < n ; ++i) {
    if (ans[i] == 0) return 0;
    if (ans[i] > 0) {
      stk.push_back(ans[i]);
    } else {
      if (ans[i] == -stk[stk.size()-1]) {
        stk.pop_back();
      } else return 0;
    }
  }
  return stk.size() == 0;
}

int main() {
  scanf("%d",&n);
  for (int i = 0 ; i < n ; ++i) {
    scanf("%d",&a[i]);
    mp[a[i]].push_back(i);
  }
  int t;
  scanf("%d",&t);
  while (t--) {
    int pos;
    scanf("%d",&pos);
    neg[pos-1] = -1;
  }
  for (itr = mp.begin() ; itr != mp.end(); ++itr) {
    vector<int> &v = itr->second;
    int cnt = 0, tot = 0;
    for (int i = v.size() - 1 ; i >= 0 ; --i) {
      if (neg[v[i]] == -1) {++cnt; ++tot;}
      else if (neg[v[i]] == 0) {
        if (cnt) {
          neg[v[i]] = 1;
          --cnt;
          ++tot;
        }
      }
    }
    int left = v.size() - tot;
    if (left % 2) {
      printf("NO\n");
      return 0;
    }
    int tmp = 0;
    for (int i = 0 ; i < v.size() ; ++i) {
      if (neg[v[i]] != 0) continue;
      if (tmp < left / 2) {
        neg[v[i]] = 1;
        ++tmp;
      } else {
        neg[v[i]] = -1;
      }
    }
    for (int i = 0 ; i < v.size() ; ++i) {
      ans[v[i]] = neg[v[i]] * (itr->first);
    }
  }
  if (check(ans)) {
    printf("YES\n");
    for (int i = 0 ; i < n ; i++) {
      if (i) printf(" ");
      printf("%d",ans[i]);
    }
    printf("\n");
  } else {
    printf("NO\n");
  }
  return 0;
}

