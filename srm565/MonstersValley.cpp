#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long long LL;
const int INF = 1000100100;
const LL LLINF = (LL)INF * INF;

LL dp[55][128];

class MonstersValley {
public:
  int minimumPrice(vector<long long> dread, vector <int> price) {
    int res;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0 ; i < dread.size() ; ++i) {
      for (int j = 0 ; j <= 2 * i ; ++j) {
        if (dp[i][j] == -1) continue;
        int tmp_dr = dp[i][j] + dread[i];
        if (tmp_dr > dp[i+1][j+price[i]])
          dp[i+1][j+price[i]] = tmp_dr;
        if (dp[i][j] >= dread[i]) {
          if (dp[i][j] > dp[i+1][j])
            dp[i+1][j] = dp[i][j];
        }
      }
    }
    int n = dread.size();
    int j;
    for (j = 0 ; j <= 110 ; ++j)
      if (dp[n][j] != -1) break;
    return j;
  }
};



// Powered by FileEdit
// Powered by CodeProcessor
