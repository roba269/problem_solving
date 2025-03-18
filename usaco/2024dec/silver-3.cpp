#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MP make_pair

const int MAXN = 1010;
const int MAXQ = 2e5 + 10;
pair<int,int> a[MAXQ];
int ans[MAXQ];
char mx[MAXN][MAXN];
int vis[MAXN][MAXN], blocker[MAXN][MAXN];
pair<int,int> que[MAXN*MAXN];
int head, tail;
int n;

const int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
inline char opposite(int d) {
    if (d == 0) return 'D';
    if (d == 1) return 'U';
    if (d == 2) return 'R';
    return 'L';
}

inline void set_blocker(int x, int y) {
    if (blocker[x][y] != 0) blocker[x][y] = 1;
}

inline void clear_blocker(int x, int y) {
    blocker[x][y] = 0;
}

void bfs() {
        while (head < tail) {
            for (int d = 0 ; d < 4 ; ++d) {
                int tx = que[head].first + dir[d][0], ty = que[head].second + dir[d][1];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                if (mx[tx][ty] == opposite(d) || mx[tx][ty] == 0) {
                    if (!vis[tx][ty]) {
                        vis[tx][ty] = 1;
                        // blocker[tx][ty] = 0;
                        clear_blocker(tx, ty);
                        que[tail++] = MP(tx, ty);
                    }
                } else {
                    // printf("set blocker[%d][%d] to 1, que[head] = (%d, %d)\n", tx, ty, que[head].first, que[head].second);
                    // blocker[tx][ty] = 1;
                    set_blocker(tx, ty);
                }
            }
            ++head;
        }
}

void output_blocker() {
    printf("----\n");
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < n ; ++j)
            if (blocker[i][j]) printf("B");
            else printf(".");
        printf("\n");
    }
    printf("----\n");
}

int main() {
    int q;
    while (scanf("%d%d",&n,&q) != EOF) {
        for (int i = 0 ; i < q ; ++i) {
            char buf[5];
            scanf("%d%d%s", &a[i].first, &a[i].second, buf);
            --a[i].first; --a[i].second;
            mx[a[i].first][a[i].second] = buf[0];
        }
        memset(vis, 0, sizeof(vis));
        memset(blocker, -1, sizeof(blocker));   // -1: unset, 0: clear, 1: blocker. always from -1 to 0 or 1, and from 1 to 0.
        head = 0, tail = 0;
        for (int i = 0 ; i < n ; ++i) {
            if (mx[0][i] == 'U' || mx[0][i] == 0) {
                if (!vis[0][i]) {que[tail++] = MP(0, i); vis[0][i] = 1;}
                clear_blocker(0, i);
            } else set_blocker(0, i);
            if (mx[n-1][i] == 'D' || mx[n-1][i] == 0) {
                if (!vis[n-1][i]) {que[tail++] = MP(n-1, i); vis[n-1][i] = 1;}
                clear_blocker(n-1, i);
            } else set_blocker(n-1, i);
            if (mx[i][0] == 'L' || mx[i][0] == 0) {
                if (!vis[i][0]) {que[tail++] = MP(i, 0); vis[i][0] = 1;}
                clear_blocker(i, 0);
            } else set_blocker(i, 0);
            if (mx[i][n-1] == 'R' || mx[i][n-1] == 0) {
                if (!vis[i][n-1]) {que[tail++] = MP(i, n-1); vis[i][n-1] = 1;}
                clear_blocker(i, n-1);
            } else set_blocker(i, n-1);
        }
        // output_blocker();
        bfs();
        // output_blocker();
        ans[q-1] = n*n-head;
        for (int i = q-1 ; i >= 1 ; --i) {
            mx[a[i].first][a[i].second] = 0;
            if (blocker[a[i].first][a[i].second] != 1) {
                ans[i-1] = ans[i];
                continue;
            }
            // blocker[a[i].first][a[i].second] = 0;
            clear_blocker(a[i].first, a[i].second);
            vis[a[i].first][a[i].second] = 1;            
            que[tail++] = MP(a[i].first, a[i].second);
            bfs();
            ans[i-1] = n*n-head;
        }
        
        for (int i = 0 ; i < q ; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}
