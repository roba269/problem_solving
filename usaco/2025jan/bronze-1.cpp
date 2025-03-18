#include <cstdio>
#include <set>
using namespace std;

const int MAXN = 1010;
char buf[MAXN][MAXN];
set<pair<int,int> > ex;

#define MP make_pair

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a, b;
        scanf("%d%d%d",&n,&b,&a);
        for (int i = 0 ; i < n ; ++i)
            scanf("%s", buf[i]);
        
        if (a == 0 && b == 0) {
            int ans = 0;
            for (int i = 0 ; i < n ; ++i)
                for (int j = 0 ; j < n ; ++j)
                    if (buf[i][j] != 'W') ++ans;
            printf("%d\n", ans);
            continue;
        }

        ex.clear();
        bool flg = true;
        int ans = 0;
        for (int i = 0 ; i < n ; ++i)
            for (int j = 0 ; j < n ; ++j) {
                if (buf[i][j] == 'W' && i+a < n && j+b < n) {
                    if (buf[i+a][j+b] == 'B') {
                        flg = false;
                        break;
                    }
                }
                if (buf[i][j] == 'B') {
                    if (i < a || j < b || (i-a >= 0 && j-b >= 0 && buf[i-a][j-b] == 'W')) {
                        flg = false;
                        break;
                    }
                    ++ans;
                    if (i-a >= 0 && j-b >= 0 && buf[i-a][j-b] == 'G') {
                        ex.insert(MP(i-a, j-b));
                        ++ans;
                    }
                    if (i+a < n && j+b < n && buf[i+a][j+b] == 'G') {
                        ex.insert(MP(i+a, j+b));
                    }
                }
            }
        
        if (!flg) {
            printf("-1\n");
            continue;
        }
        for (int i = 0 ; i < n ; ++i)
            for (int j = 0 ; j < n ; ++j)
                if (buf[i][j] == 'G' && ex.count(MP(i,j)) == 0) {
                    ++ans;
                    ex.insert(MP(i, j));
                    ex.insert(MP(i+a, j+b));
                }

        printf("%d\n", ans);
    }
    return 0;
}