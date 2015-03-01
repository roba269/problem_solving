#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 100010;
vector<int> pt[MAXN];
int vis[MAXN], pre[MAXN], q[MAXN];
vector<int> fq[MAXN];
int weight[MAXN];

int N, D;

int hashcode(vector<int> p) {
  int c = 0;
  for (int i = 0 ; i < p.size() ; ++i) {
    c = c * N + p[i];
  }
  return c;
}

vector<int> decode(int hash) {
  vector<int> res;
  for (int i = 0 ; i < D ; ++i) {
    res.push_back(hash % N);
    hash /= N;
  }
  for (int i = 0 ; i < D/2 ; ++i) {
    swap(res[i], res[D-1-i]);
  }
  return res;
}

int dist(const vector<int> &a, const vector<int> &b) {
  int s = 0;
  for (int i = 0 ; i < D ; ++i)
    s += abs(a[i]-b[i]);
  return s;
}

int main() {
  int T, k;
  scanf("%d",&T);
  for (int ca = 0; ca < T ; ++ca) {
    // printf("case %d\n", ca);
    scanf("%d%d%d",&N,&D,&k);
    // printf("N:%d D:%d k:%d\n", N, D, k);
    for (int i = 0 ; i < k ; ++i) {
      pt[i] = vector<int>(D);
      for (int j = 0 ; j < D ; ++j) {
        scanf("%d",&pt[i][j]);
        --pt[i][j];
      }
    }
    int ans = 0;
    int cnt = 1;
    for (int i = 0 ; i < D ; ++i) {
      weight[D-1-i] = cnt;
      cnt *= N;
    }
    for (int i = 0 ; i < cnt ; ++i) {
      pre[i] = dist(decode(i), pt[0]);
      ans += pre[i];
    }
    // cout << ans << endl;
    printf("%d\n", ans);
    memset(vis, 0, sizeof(vis));
    for (int i = 1 ; i < k ; ++i) {
      int st = hashcode(pt[i]);
      q[0] = st; vis[st] = i;
      fq[0] = pt[i];
      ans -= pre[st];
      pre[st] = 0;
      int qh, qt;
      for (qh = 0, qt = 1 ; qh < qt ; ++qh) {
        // vector<int> curp = decode(q[qh]);
        vector<int>& curp = fq[qh];
        int ori_hash = hashcode(curp);
        for (int d = 0 ; d < D ; ++d) {
          for (int flg = -1 ; flg <= 1 ; flg += 2) {
            curp[d] += flg;
            if (curp[d] < 0 || curp[d] >= N) {
              curp[d] -= flg;
              continue;
            }
            // int tmp_hash = hashcode(curp);
            int tmp_hash = ori_hash + flg * weight[d];
            if (vis[tmp_hash] != i) {
              vis[tmp_hash] = i;
              int new_dist = dist(curp, pt[i]);
              if (new_dist < pre[tmp_hash]) {
                ans -= pre[tmp_hash];
                ans += new_dist;
                pre[tmp_hash] = new_dist;
                fq[qt] = curp;
                q[qt++] = tmp_hash;
              }
            }
            curp[d] -= flg;
          }
        }
      }
      // cout << ans << endl;
      printf("%d\n", ans);
    }
  }
  return 0;
}

