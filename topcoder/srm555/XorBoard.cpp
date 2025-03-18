/* SRM 555 Div1 Lev2 AC */
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
const int MOD = 555555555;
const int MAXN = 1560;
int cc[MAXN*2][MAXN];

class XorBoard {
public:
  void init() {
    cc[0][0] = 1;
    for (int i = 1 ; i < MAXN*2 ; ++i)
      for (int j = 0 ; j <= min(i, MAXN-1) ; ++j)
        if (j == 0 || j == i) cc[i][j] = 1;
        else cc[i][j] = (cc[i-1][j-1] + cc[i-1][j]) % MOD;
  }
  int count(int H, int W, int Rcount, int Ccount, int S) {
    init();
    int res = 0, x, y;
    for (x = 0 ; x <= H ; ++x) {
      int flg = 0;
      if (2*x != H) {
        if ((S - x * W) % (H - 2*x) == 0)
          y = (S - x * W) / (H - 2*x);
        else continue;
      } else {
        if (H * W == 2*S) {
          flg = 1;
        }
        else continue;
      }
      int kx, ky;
      if (x <= Rcount && (Rcount - x) % 2 == 0) {
        kx = (Rcount - x) / 2;
      } else continue;
      if (flg == 0) {
        if (y <= Ccount && y >= 0 && y <= W && (Ccount - y) % 2 == 0) {
          ky = (Ccount - y) / 2;
        } else continue;
        // printf("x:%d y:%d kx:%d ky:%d\n",x,y,kx,ky);
        LL tmp = ((LL)cc[H][x] * cc[kx-1+H][H-1]) % MOD;
        tmp = tmp * cc[W][y] % MOD;
        tmp = tmp * cc[ky-1+W][W-1] % MOD;
        res = (res + tmp) % MOD;
      } else {
        // y can be any value
        LL tmp = ((LL)cc[H][x] * cc[kx-1+H][H-1]) % MOD;
        tmp = tmp * cc[Ccount-1+W][W-1] % MOD;
        res = (res + tmp) % MOD;
      }
    }
    return res;
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
        XorBoard theObject;
        eq(0, theObject.count(2, 2, 2, 2, 4),4);
    }
    {
        XorBoard theObject;
        eq(1, theObject.count(2, 2, 0, 0, 1),0);
    }
    {
        XorBoard theObject;
        eq(2, theObject.count(10, 20, 50, 40, 200),333759825);
    }
    {
        XorBoard theObject;
        eq(3, theObject.count(1200, 1000, 800, 600, 4000),96859710);
    }
    {
        XorBoard theObject;
        eq(4, theObject.count(555, 555, 555, 555, 5550),549361755);
    }
  return 0;
}
// END CUT HERE
