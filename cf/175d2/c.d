import std.stdio;
import std.math;
import std.algorithm;
/*
int myabs(int a) {
  if (a < 0) return -a;
  return a;
}
*/
void main() {
  int n;
  scanf("%d",&n);
  int[] a = new int[n];
  for (int i = 0 ; i < n ; ++i)
    scanf("%d",&a[i]);
  sort(a);
  ulong ans = 0;
  foreach (int idx, ele ; a) {
    ans += abs(idx-ele+1);
  }
  writef("%d\n", ans);
}

