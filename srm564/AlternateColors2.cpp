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

const int MAXN = 100010;

inline int get_inter(int a, int b, int c, int d) {
  int s = max(0,max(a, c));
  int t = min(b, d);
  if (s > t) return 0;
  return t - s + 1;
}

class AlternateColors2 {
public:
  long long countWays(int n, int k) {
    long long res = 0;
    for (int x = 0 ; x <= k-1 ; ++x) {
      if (3 * x == k-1) {
        // two full
        int left = n - k;
        res += (LL)(left + 2) * (left + 1) / 2;
        continue;
      }
      if (k-1 < 3 * x && k-1 >= 2 * x) {
        // one full
        int left = n - k;
        res += (left + 1) * 2;
      }
      res += get_inter(0, x-1, k-2*x, k-x-1); 
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
        AlternateColors2 theObject;
        eq(0, theObject.countWays(1, 1),1LL);
    }
    {
        AlternateColors2 theObject;
        eq(1, theObject.countWays(3, 3),3LL);
    }
    {
        AlternateColors2 theObject;
        eq(2, theObject.countWays(6, 4),9LL);
    }
    
    {
        AlternateColors2 theObject;
        eq(3, theObject.countWays(6, 1),21LL);
    }
    {
        AlternateColors2 theObject;
        eq(4, theObject.countWays(1000, 2),1LL);
    }
    {
        AlternateColors2 theObject;
        eq(5, theObject.countWays(100000, 100000),1666700000LL);
    }
    
  return 0;
}
// END CUT HERE
