/* SRM 562 Div 2 Lev 3 */
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

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 1000100100;
const LL LLINF = (LL)INF * INF;
LL dp[2][1<<14][14];
int bp[20][20];

class RandomOption {
public:
  double getProbability(int n, vector <int> b1, vector <int> b2) {
    // for (int i = 0 ; i < n ; i++) bp[i].clear();
    CLEAR(bp);
    for (int i = 0 ; i < b1.size() ; ++i) {
      bp[b1[i]][b2[i]] = 1;
      bp[b2[i]][b1[i]] = 1;
    }
    for (int i = 0 ; i < n ; ++i) {
      dp[0][1<<i][i] = 1;
    }
    int from = 0, to = 1;
    for (int i = 1 ; i < n ; ++i) {
      memset(&dp[to][0][0], 0, sizeof(dp[0]));
      for (int mask = 0 ; mask < (1<<n) ;++mask) {
        for (int ed = 0 ; ed < n ; ++ed) {
          if (dp[from][mask][ed] == 0) continue;
          for (int next = 0 ; next < n ; ++next) {
            if (mask & (1<<next)) continue;
            if (bp[ed][next]) continue;
            dp[to][mask+(1<<next)][next] += dp[from][mask][ed];
          }
        }
      }
      from = 1 - from;
      to = 1 - to;
    }
    double tot = 0;
    for (int ed = 0 ; ed < n ; ++ed)
      tot += dp[from][(1<<n)-1][ed];
    for (int i = 1 ; i <= n ; i++)
      tot /= i;
    return tot;
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
        int badLane1ARRAY[] = {0};
        vector <int> badLane1( badLane1ARRAY, badLane1ARRAY+ARRSIZE(badLane1ARRAY) );
        int badLane2ARRAY[] = {3};
        vector <int> badLane2( badLane2ARRAY, badLane2ARRAY+ARRSIZE(badLane2ARRAY) );
        RandomOption theObject;
        eq(0, theObject.getProbability(5, badLane1, badLane2),0.6);
    }
    {
        int badLane1ARRAY[] = {0, 1, 2};
        vector <int> badLane1( badLane1ARRAY, badLane1ARRAY+ARRSIZE(badLane1ARRAY) );
        int badLane2ARRAY[] = {1, 2, 0};
        vector <int> badLane2( badLane2ARRAY, badLane2ARRAY+ARRSIZE(badLane2ARRAY) );
        RandomOption theObject;
        eq(1, theObject.getProbability(5, badLane1, badLane2),0.1);
    }
    {
        int badLane1ARRAY[] = {2, 2, 2, 2};
        vector <int> badLane1( badLane1ARRAY, badLane1ARRAY+ARRSIZE(badLane1ARRAY) );
        int badLane2ARRAY[] = {0, 1, 3, 4};
        vector <int> badLane2( badLane2ARRAY, badLane2ARRAY+ARRSIZE(badLane2ARRAY) );
        RandomOption theObject;
        eq(2, theObject.getProbability(5, badLane1, badLane2),0.0);
    }
    {
        int badLane1ARRAY[] = {0, 1, 2};
        vector <int> badLane1( badLane1ARRAY, badLane1ARRAY+ARRSIZE(badLane1ARRAY) );
        int badLane2ARRAY[] = {6, 5, 4};
        vector <int> badLane2( badLane2ARRAY, badLane2ARRAY+ARRSIZE(badLane2ARRAY) );
        RandomOption theObject;
        eq(3, theObject.getProbability(7, badLane1, badLane2),0.3904761904761904);
    }
    {
        int badLane1ARRAY[] = {3, 5, 1, 0, 2, 6, 4};
        vector <int> badLane1( badLane1ARRAY, badLane1ARRAY+ARRSIZE(badLane1ARRAY) );
        int badLane2ARRAY[] = {0, 2, 4, 6, 1, 5, 3};
        vector <int> badLane2( badLane2ARRAY, badLane2ARRAY+ARRSIZE(badLane2ARRAY) );
        RandomOption theObject;
        eq(4, theObject.getProbability(7, badLane1, badLane2),0.09166666666666667);
    }
  return 0;
}
// END CUT HERE
