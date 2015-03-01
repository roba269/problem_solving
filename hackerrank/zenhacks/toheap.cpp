#include <cstdio>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

typedef long long LL;
const int MAXN = 200010;
const int MOD = (1e9) + 7;
int a[MAXN], rt[MAXN];
unordered_map<int,int> mp[MAXN];
int n;

LL solve(int st, int ed) {
  if (rt[st] < ed) return 0;
  if (st + 1 == ed) return 1;
  if (mp[st].find(ed) != mp[st].end()) return mp[st][ed];
  if (rt[st+1] < ed) {
    LL lans = solve(st+1, rt[st+1]);
    LL rans = solve(rt[st+1], ed);
    return mp[st][ed] = lans * rans % MOD;
  }
  LL ans = 0;
  for (int i = st + 2 ; i < ed ; ++i) {
    if (rt[i] < ed) continue;
    ans += solve(st+1, i) * solve(i, ed) % MOD;
    ans %= MOD;
  }
  return mp[st][ed] = ans;
}

int main() {
  while (scanf("%d",&n) != EOF) {
    for (int i = 0 ; i < n ; ++i)
      scanf("%d",&a[i]);
    stack<pair<int,int> > stk;
    for (int i = n - 1 ; i >= 0 ; --i) {
      while (!stk.empty() && a[i] >= stk.top().first)
        stk.pop();
      if (stk.empty()) {
        rt[i] = n;
      } else rt[i] = stk.top().second;
      stk.push(make_pair(a[i], i));
    }
    LL ans = solve(0, n);
    cout << ans << endl;
  }
  return 0;
}

