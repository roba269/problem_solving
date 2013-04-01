import std.stdio;

void main() {
  int n, s, t;
  scanf("%d %d %d", &n, &s, &t);
  int[] p = new int[n+1];
  for (int i = 1 ; i <= n ; ++i) {
    scanf("%d", &p[i]);
  }
  int ans = 0, flg = 1;
  bool[int] set;
  for ( ; s != t ; ++ans) {
    if (s in set) {flg = 0; break;}
    set[s] = true;
    s = p[s];
  }
  if (!flg) writeln("-1");
  else writeln(ans);
}

