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
#include <cassert>
using namespace std;

#define PB push_back
#define MP make_pair
#define SQR(x) ((x)*(x))
#define CLEAR(x) memset((x), 0, sizeof(x))
#define SET(x, y) memset((x), (y), sizeof(x))

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 1000100100;
const LL LLINF = (LL)INF * INF;
const int MAXN = 55;
string col = "RGB";

class Stamp {
public:
  int n, dp[MAXN][3];
  string s;
  int check(int st, int ed, int c) {
    for (int i = st - 1 ; i < ed ; ++i)
      if (s[i] != '*' && s[i] != col[c]) return 0;
    return 1;
  }
  int getMinimumCost(string _s, int stampCost, int pushCost) {
    s = _s; n = s.size();
    int best = INF;
    for (int L = 1 ; L <= n ; ++L) {
      int c = stampCost * L;
      SET(dp, 0x3f);
      for (int i = 0 ; i < 3 ; ++i) dp[0][i] = c;
      for (int i = L ; i <= n ; ++i) {
        for (int st = i - L + 1 ; st < i ; ++st) {
          for (int k = 0 ; k < 3 ; ++k) {
            if (check(st+1, i, k) == 0) continue;
            if (dp[st][k] <= INF && dp[i][k] > dp[st][k] + pushCost)
              dp[i][k] = dp[st][k] + pushCost;
          }
        }
        int minc = INF;
        for (int k = 0 ; k < 3 ; ++k) {
          if (dp[i-L][k] < minc) minc = dp[i-L][k];
        }
        for (int k = 0 ; k < 3 ; ++k) {
          if (check(i-L+1, i, k) && dp[i][k] > minc + pushCost)
            dp[i][k] = minc + pushCost;
        }
      }
      for (int k = 0 ; k < 3 ; ++k) {
        if (dp[n][k] < best) best = dp[n][k];
      }
    }
    return best;
  }
};

// BEGIN CUT HERE

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main( int argc, char* argv[] ) {
  
    {
        Stamp theObject;
        eq(0, theObject.getMinimumCost("RRGGBB", 1, 1),5);
    }
    {
        Stamp theObject;
        eq(1, theObject.getMinimumCost("R**GB*", 1, 1),5);
    }
    
    {
        Stamp theObject;
        eq(2, theObject.getMinimumCost("BRRB", 2, 7),30);
    }
    {
        Stamp theObject;
        eq(3, theObject.getMinimumCost("R*RR*GG", 10, 58),204);
    }
    {
        Stamp theObject;
        eq(4, theObject.getMinimumCost("*B**B**B*BB*G*BBB**B**B*", 5, 2),33);
    }
    {
        Stamp theObject;
        eq(5, theObject.getMinimumCost("*R*RG*G*GR*RGG*G*GGR***RR*GG", 7, 1),30);
    }
  return 0;
}
// END CUT HERE
