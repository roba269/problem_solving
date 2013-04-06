#include <cstdio>

using namespace std;
const int MAXN = 100010;

int a[MAXN];
int n;

void gen() {
  int up;
  if (n % 4 == 0) up = n / 2;
  else up = n / 2;
  for (int i = 1 ; i < up ; i += 2) {
    a[i] = i + 1;
    a[i+1] = n-i+1;
    a[n-i+1] = n-i;
    a[n-i] = i;
  }
}

int main() {
  scanf("%d",&n);
  if (n % 4 != 0 && n % 4 != 1) {
    printf("-1\n");
  } else {
    gen();
    if (n % 4) {
      a[(n+1)/2] = (n+1)/2;
    }
    for (int i = 1 ; i <= n ; i++) {
      if (i>1) printf(" ");
      printf("%d",a[i]);
    }
    printf("\n");
  }
  return 0;
}

