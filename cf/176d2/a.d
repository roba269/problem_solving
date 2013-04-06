import std.stdio;

int check(string[] mp) {
  for (int i = 0 ; i < 3 ; ++i)
    for (int j = 0 ; j < 3 ; ++j)
      if (mp[i][j] == mp[i+1][j] && mp[i][j] == mp[i][j+1]
          && mp[i][j] == mp[i+1][j+1]) return 1;
  return 0;
}

void flip(ref char a) {
  if (a == '#') a = '.';
  else a = '#';
}

void main() {
  string[] mp = new string[4];
  for (int i = 0 ; i < 4 ; ++i)
    mp[i] = readln();
  int flg = 0;
L:
  for (int i = 0 ; i < 4 ; ++i)
    for (int j = 0 ; j < 4 ; ++j) {
      flip(mp[i][j]);
      if (check(mp)) {flg = 1; break L;}
      flip(mp[i][j]);
      if (check(mp)) {flg = 1; break L;}
    }
  printf("%s\n", flg?"YES":"NO");
}

