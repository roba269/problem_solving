import std.stdio;

void main() {
  int n, k;
  int[] ans;
  readf("%d %d", &n, &k);
  for (int i = k + 1 ; i >= 1 ; --i) {
    ans ~= i;
  }
  for (int i = k + 2 ; i <= n ; ++i) {
    ans ~= i;
  }
  foreach (v ; ans) {
    write(v);
    write(" ");
  }
  write("\n");
}
