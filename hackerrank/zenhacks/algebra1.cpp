#include <cstdio>

const int MAXN = 112;
int a[MAXN][MAXN];
int n;
int g_e;

bool is_quasigroup() {
  for (int x = 0 ; x < n ; ++x)
    for (int y = 0 ; y < n ; ++y) {
      int cnt = 0;
      for (int z = 0 ; z < n ; ++z)
        if (a[x][z] == y) ++cnt;
      if (cnt != 1) return false;
      cnt = 0;
      for (int w = 0 ; w < n ; ++w)
        if (a[w][x] == y) ++cnt;
      if (cnt != 1) return false;
    }
  return true;
}

bool is_loop() {
  if (!is_quasigroup()) return false;
  int tot = 0;
  for (int e = 0 ; e < n ; ++e) {
    int cnt = 0;
    for (int x = 0 ; x < n ; ++x) {
      if (a[e][x] == a[x][e] && a[e][x] == x)
        ++cnt;
    }
    if (cnt == n) ++tot;
  }
  return tot == 1;
}

bool is_semigroup() {
  for (int x = 0 ; x < n ; ++x)
    for (int y = 0;  y < n ; ++y)
      for (int z = 0 ; z < n ; ++z)
        if (a[a[x][y]][z] != a[x][a[y][z]]) return false;
  return true;
}

bool is_monoid() {
  if (!is_semigroup()) return false;
  int tot = 0;
  for (int e = 0 ; e < n ; ++e) {
    int cnt = 0;
    for (int x = 0 ; x < n ; ++x) {
      if (a[e][x] == a[x][e] && a[e][x] == x)
        ++cnt;
    }
    if (cnt == n) {
      ++tot;
      g_e = e;
    }
  }
  return tot == 1;
}

bool is_group() {
  if (!is_monoid()) return false;
  for (int x = 0 ; x < n ; ++x) {
    int flg = 0;
    for (int y = 0 ; y < n ; ++y)
      if (a[x][y] == a[y][x] && a[x][y] == g_e)
        flg = 1;
    if (!flg) return false;
  }
  return true;
}

bool is_abel() {
  if (!is_group()) return false;
  for (int x = 0 ; x < n ; ++x)
    for (int y = 0 ; y < n ; ++y)
      if (a[x][y] != a[y][x]) return false;
  return true;
}

bool is_rack() {
  for (int x = 0 ; x < n ; ++x)
    for (int y = 0 ; y < n ; ++y)
      for (int z = 0 ; z < n ; ++z)
        if (a[x][a[y][z]] != a[a[x][y]][a[x][z]])
          return false;
  for (int x = 0 ; x < n ;++x)
    for (int y = 0 ; y < n ; ++y) {
      int cnt = 0;
      for (int z = 0 ; z < n ; ++z)
        if (a[x][z] == y) ++cnt;
      if (cnt != 1) return false;
    }
  return true;
}

bool is_quandle() {
  if (!is_rack()) return false;
  for (int x = 0 ; x < n ; ++x)
    if (a[x][x] != x) return false;
  return true;
}

int main() {
  int T;
  scanf("%d",&T);
  while (T--) {
    scanf("%d",&n);
    for (int i = 0 ; i < n ; ++i)
      for (int j = 0 ; j < n ; ++j)
        scanf("%d", &a[i][j]);
    int flg = 1;
    for (int i = 0 ; i < n ; ++i)
      for (int j = 0 ; j < n ; ++j)
        if (a[i][j] < 0 || a[i][j] >= n)
          flg = 0;
    if (!flg) {printf("0\n"); continue;}
    int s = 0;
    if (is_quasigroup()) s += 1;
    if (is_loop()) s += 2;
    if (is_semigroup()) s += 4;
    if (is_monoid()) s += 8;
    if (is_group()) s += 16;
    if (is_abel()) s += 32;
    if (is_rack()) s += 64;
    if (is_quandle()) s += 128;
    printf("%d\n", s);
  }
  return 0;
}

