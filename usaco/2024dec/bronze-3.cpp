#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 20010;
char buf[MAXN];
vector<pair<char,char> > ans;
bool vis[MAXN];
int n;

bool check(char i, char j, int c) {
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int x = 0 ; x + 2 <= n-1 ; ) {
        if (buf[x] == i && buf[x+1] == j && buf[x+2] == j) {
            ++cnt;
            vis[x] = vis[x+1] = vis[x+2] = true;
            x += 3;
        }
        else ++x;
    }
    for (int x = 0 ; x + 2 <= n -1 ; ++x) {
        if (vis[x] || vis[x+1] || vis[x+2]) continue;
        int tmp = 0;
        if (buf[x] == i) ++tmp;
        if (buf[x+1] == j) ++tmp;
        if (buf[x+2] == j) ++tmp;
        if (tmp == 2) {
            ++cnt;
            break;
        }
    }
    return cnt >= c;
}

int main() {
    int c;
    scanf("%d%d",&n,&c);
    scanf("%s", buf);
    for (char i = 'a' ; i <= 'z' ; ++i)
        for (char j = 'a' ; j <= 'z' ; ++j) {
            if (i == j) continue;
            if (check(i, j, c)) ans.push_back(make_pair(i, j));
        }
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%c%c%c\n", p.first, p.second, p.second);
    }
    return 0;
}