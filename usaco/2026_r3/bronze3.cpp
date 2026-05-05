#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

const int MAXN = 1010;
char buf[MAXN][MAXN];
char target[MAXN];
set<pair<int,int>> pos[26];

vector<vector<int>> ans;

void do_swap(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return;
    if (y1 != y2 && buf[x2][y1] != buf[x2][y2]) {
        // swap (x2, y1) <--> (x2, y2)
        ans.push_back({1, x2, y1, y2});
        pos[buf[x2][y1]-'a'].erase(make_pair(x2, y1));
        pos[buf[x2][y1]-'a'].insert(make_pair(x2, y2));
        pos[buf[x2][y2]-'a'].erase(make_pair(x2, y2));
        pos[buf[x2][y2]-'a'].insert(make_pair(x2, y1));        
        swap(buf[x2][y1], buf[x2][y2]);
    }
    if (x1 != x2 && buf[x2][y1] != buf[x1][y1]) {
        // swap (x2, y1) <--> (x1, y1)
        ans.push_back({2, x1, x2, y1});
        pos[buf[x2][y1]-'a'].erase(make_pair(x2, y1));
        pos[buf[x2][y1]-'a'].insert(make_pair(x1, y1));
        pos[buf[x1][y1]-'a'].erase(make_pair(x1, y1));
        pos[buf[x1][y1]-'a'].insert(make_pair(x2, y1));        
        swap(buf[x2][y1], buf[x1][y1]);
    }
}

int main() {
    int T, n, m;
    scanf("%d", &T);
    for (int ca = 1 ; ca <= T ; ++ca) {
        scanf("%d%d",&n,&m);
        scanf("%s", target);
        for (int i = 0 ; i < 26 ; ++i)
            pos[i].clear();
        for (int i = 0 ; i < n ; ++i) {
            scanf("%s", buf[i]);
            for (int j = 0 ; j < m ; ++j) {
                pos[buf[i][j]-'a'].insert(make_pair(i,j));
            }
        }
        ans.clear();
        for (int j = 0 ; j < m ; ++j) {
            assert(pos[target[j]-'a'].size() > 0);
            auto p = pos[target[j]-'a'].begin();
            do_swap(0, j, p->first, p->second);
            pos[target[j]-'a'].erase(make_pair(0, j));         
            assert(buf[0][j] == target[j]);
        }
        printf("%d\n", ans.size());
        for (int i = 0 ; i < ans.size() ; ++i)
            printf("%d %d %d %d\n", ans[i][0], ans[i][1]+1, ans[i][2]+1, ans[i][3]+1);
    }
    return 0;
}