#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1010;
int a[MAXN][MAXN];
int cnt[MAXN*2];
int n;

void try_out(int lo_idx, int hi_idx, vector<int> &ans) {
    int mp[MAXN*2];
    for (int j = 0 ; j < n ; ++j) {
        mp[a[lo_idx][j]] = cnt[a[lo_idx][j]] + 1;
    }
    for (int j = 0 ; j < n ; ++j) {
        mp[a[hi_idx][j]] = n * 2 + 1 - cnt[a[hi_idx][j]];
    }
    ans.clear();
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < n ; ++j)
            ans.push_back(mp[a[i][j]]);
    }   
}

void output(const vector<int> &v) {
    int p = 0;
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < n ; ++j) {
            if (j) printf(" ");
            printf("%d", v[p++]);
        }
        printf("\n");
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j) {
            scanf("%d", &a[i][j]);
            cnt[a[i][j]]++;
        }

    vector<int> candidate_row;
    for (int i = 0 ; i < n ; ++i) {
        int vis[MAXN] = {0};
        bool flg = true;
        for (int j = 0 ; j < n ; ++j) {
            if (!vis[cnt[a[i][j]]]) {
                vis[cnt[a[i][j]]] = 1;
            } else {
                flg = false;
                break;
            }
        }
        if (!flg) continue;

        // we found the row whose each elements appears 1,2,3...,n times persepctively
        // there will be two such kind of rows, representing the original matrix row [2, 3, 4, ..., (n+1)] and [n+1, n+2, ... 2n]
        // so we just try these two cases to find the best answer
        candidate_row.push_back(i);
    }

    vector<int> ans1, ans2;
    try_out(candidate_row[0], candidate_row[1], ans1);
    try_out(candidate_row[1], candidate_row[0], ans2);
    
    int cmp = 0;
    for (int i = 0 ; i < ans1.size() ; ++i)
        if (ans1[i] != ans2[i]) {cmp = ans1[i] - ans2[i]; break;}
    if (cmp < 0) output(ans1);
    else output(ans2);
    return 0;
}